#ifndef HELPER_H
#define HELPER_H

using namespace std;

//Hashed algorithm for PC: Cyclic Redundancy Check (CRC)
uint64_t CRC(uint64_t address){
	unsigned long long crcPolynomial = 3988292384ULL;  //Decimal value for 0xEDB88320 hex value
    unsigned long long result = address;
    for(unsigned int i = 0; i < 32; i++ )
    	if((result & 1 ) == 1 ){
    		result = (result >> 1) ^ crcPolynomial;
    	}
    	else{
    		result >>= 1;
    	}
    return result;
}

//Information for each address
struct HISTORY{
    uint64_t address;
    uint64_t PCval;
    uint32_t previousVal;
    uint32_t lru;
    bool prefetching;

    void init(){
        PCval = 0;
        previousVal = 0;
        lru = 0;
        prefetching = false;
    }

    void update(unsigned int currentVal, uint64_t PC){
        previousVal = currentVal;
        PCval = PC;
    }

    void set_prefetch(){
        prefetching = true;
    }
};

#endif