//      Hawkeye with Belady's Algorithm   //
//             Replacement Policy         //

//Code for Hawkey configurations of 1 and 2 in Champsim
#include "../inc/champsim_crc2.h"
#include "hawkeye_predictor.h"
#include "optgen.h"
#include "helper_function.h"

#define NUM_CORE 1
#define LLC_SETS NUM_CORE*2048
#define LLC_WAYS 16

//3-bit RRIP counter
#define MAXRRIP 7
uint32_t rrip[LLC_SETS][LLC_WAYS];

// initialize replacement state
void InitReplacementState()
{
    cout << "Initialize Hawkeye replacement policy state" << endl;

    for (int i=0; i<LLC_SETS; i++) {
        for (int j=0; j<LLC_WAYS; j++) {
            rrip[i][j] = MAXHIT
        }
    }

}

// find replacement victim
// return value should be 0 ~ 15 or 16 (bypass)
uint32_t GetVictimInSet (uint32_t cpu, uint32_t set, const BLOCK *current_set, uint64_t PC, uint64_t paddr, uint32_t type)
{
    return 0;
}

// called on every cache hit and cache fill
void UpdateReplacementState (uint32_t cpu, uint32_t set, uint32_t way, uint64_t paddr, uint64_t PC, uint64_t victim_addr, uint32_t type, uint8_t hit)
{
    // update lru replacement state
    // for (uint32_t i=0; i<LLC_WAYS; i++) {
    //     if (lru[set][i] < lru[set][way]) {
    //         lru[set][i]++;

    //         if (lru[set][i] == LLC_WAYS)
    //             assert(0);
    //     }
    // }
    // lru[set][way] = 0; // promote to the MRU position
}

// use this function to print out your own stats at the end of simulation
void PrintStats()
{
    int hits = 0;
    int access = 0;
    for(int i = 0; i < LLC_SETS; i++){
        // access += a
        access += 1;
    }

    cout<< "OPTGen Hits: " << hits << endl;
    cout<< "OPTGEN Hit Rate: " << 100*((double)hits / (double)access )<< endl;

}