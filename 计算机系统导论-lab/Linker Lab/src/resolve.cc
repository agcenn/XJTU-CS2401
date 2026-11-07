#include "resolve.h"
#include <map>
#include <iostream>

#define FOUND_ALL_DEF 0
#define MULTI_DEF 1
#define NO_DEF 2

std::string errSymName;

int callResolveSymbols(std::vector<ObjectFile> &allObjects);

void resolveSymbols(std::vector<ObjectFile> &allObjects) {
    int ret = callResolveSymbols(allObjects);
    if (ret == MULTI_DEF) {
        std::cerr << "multiple definition for symbol " << errSymName << std::endl;
        abort();
    } else if (ret == NO_DEF) {
        std::cerr << "undefined reference for symbol " << errSymName << std::endl;
        abort();
    }
}

/* bind each undefined reference (reloc entry) to the exact valid symbol table entry
 * Throw correct errors when a reference is not bound to definition,
 * or there is more than one definition.
 */
int callResolveSymbols(std::vector<ObjectFile> &allObjects)
{
    /* Your code here */
    // if found multiple definition, set the errSymName to problematic symbol name and return MULTIDEF;
    // if no definition is found, set the errSymName to problematic symbol name and return NODEF;

    std::map<std::string, Symbol *> strongMap;
    std::map<std::string, Symbol *> weakMap;

    //收集强符号和弱符号
    for (auto &obj : allObjects) {
        for (auto &sym : obj.symbolTable) {

            if (sym.name.empty()) {
                continue;
            }

            bool isStrong =
                sym.bind == STB_GLOBAL &&
                sym.index != SHN_UNDEF &&
                sym.index != SHN_COMMON;

            bool isWeak =
                sym.bind == STB_WEAK ||
                sym.index == SHN_COMMON;

            if (isStrong) {
                if (strongMap.count(sym.name)) {
                    errSymName = sym.name;
                    return MULTI_DEF;
                }

                strongMap[sym.name] = &sym;
            }
            else if (isWeak) {
                if (!weakMap.count(sym.name)) {
                    weakMap[sym.name] = &sym;
                }
            }
        }
    }

    //解析每个 relocation 需要的符号
    for (auto &obj : allObjects) {
        for (auto &re : obj.relocTable) {

            std::string name = re.sym->name;

            if (strongMap.count(name)) {
                re.sym = strongMap[name];
            }
            else if (weakMap.count(name)) {
                re.sym = weakMap[name];
            }
            else {
                errSymName = name;
                return NO_DEF;
            }
        }
    }


    return FOUND_ALL_DEF;
}
