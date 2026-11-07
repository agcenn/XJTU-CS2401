#include "relocation.h"

#include <sys/mman.h>

void handleRela(std::vector<ObjectFile> &allObject, ObjectFile &mergedObject, bool isPIE)
{
    /* When there is more than 1 objects, 
     * you need to adjust the offset of each RelocEntry
     */
    /* Your code here */

    /* in PIE executables, user code starts at 0xe9 by .text section */
    /* in non-PIE executables, user code starts at 0xe6 by .text section */
    uint64_t userCodeStart = isPIE ? 0xe9 : 0xe6;
    uint64_t textOff = mergedObject.sections[".text"].off + userCodeStart;
    uint64_t textAddr = mergedObject.sections[".text"].addr + userCodeStart;

    /* Your code here */

    uint64_t offset = 0;

    for (auto &obj : allObject) {
    for (auto &re : obj.relocTable) {
        re.offset += offset;
    }
    offset += obj.sections[".text"].size;
}

    for (auto &obj : allObject){
        for(auto &re : obj.relocTable){
            uint64_t S = re.sym->value;       
            int64_t A = re.addend;           
            uint64_t P = textAddr + re.offset;

            uint64_t addr = (uint64_t)mergedObject.baseAddr + textOff + re.offset;
            
            if(re.type == 10){
            int valueToFill =  S + A;
            *reinterpret_cast<int *>(addr) = valueToFill;
            }
            else if (re.type == 2 || re.type == 4) {
            int valueToFill = S + A - P;
           *reinterpret_cast<int *>(addr) = valueToFill;
        }

        }
    }
}