//      Hawkeye with Belady's Algorithm   //
//             Replacement Policy         //

//Code for Hawkey configurations of 1 and 2 in Champsim
#include "../inc/champsim_crc2.h"
#include <map>

#define NUM_CORE 1
#define LLC_SETS NUM_CORE*2048
#define LLC_WAYS 16

//3-bit RRIP counter
#define MAXRRIP 7
uint32_t rrip[LLC_SETS][LLC_WAYS];

#include "hawkeye_predictor.h"
#include "optgen.h"
#include "helper_function.h"

//Hawkeye predictors for demand and prefetch requests
Hawkeye_Predictor* predictor_demand;    //2K entries, 5-bit counter per each entry
Hawkeye_Predictor* predictor_prefetch;  //2K entries, 5-bit counter per each entry

OPTgen optgen_occup_vector[LLC_SETS];   //64 vecotrs, 128 entries each

//Prefectching
bool prefetching[LLC_SETS][LLC_WAYS];

//Sampler components tracking cache history
#define SAMPLER_ENTRIES 2800
#define SAMPLER_HIST 8
#define SAMPLER_SETS SAMPLER_ENTRIES/SAMPLER_HIST
vector<map<uint64_t, HISTORY>> cache_history_sampler;  //2800 entries, 4-bytes per each entry
uint64_t sample_signature[LLC_SETS][LLC_WAYS];

//History time
#define TIMER_SIZE 1024
uint64_t set_timer[LLC_SETS];   //64 sets, where 1 timer is used for every set


// Initialize replacement state
void InitReplacementState()
{
    cout << "Initialize Hawkeye replacement policy state" << endl;

    for (int i=0; i<LLC_SETS; i++) {
        for (int j=0; j<LLC_WAYS; j++) {
            rrip[i][j] = MAXRRIP;
            sample_signature[i][j] = 0;
            prefetching[i][j] = false;
        }
        set_timer[i] = 0;
        optgen_occup_vector[i].init(LLC_WAYS-2);
    }

    cache_history_sampler.resize(SAMPLER_SETS);
    for(int i = 0; i < SAMPLER_SETS; i++){
        cache_history_sampler[i].clear();
    }

    predictor_prefetch = new Hawkeye_Predictor();
    predictor_demand = new Hawkeye_Predictor();

    cout << "Finished initializing Hawkeye" << endl;
}

// Find replacement victim
// return value should be 0 ~ 15 or 16 (bypass)
uint32_t GetVictimInSet (uint32_t cpu, uint32_t set, const BLOCK *current_set, uint64_t PC, uint64_t paddr, uint32_t type)
{
    return 0;
}

// Called on every cache hit and cache fill
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

// Use this function to print out your own stats on every heartbeat 
void PrintStats_Heartbeat()
{

}

// Use this function to print out your own stats at the end of simulation
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