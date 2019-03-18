#ifndef HELPER_H
#define HELPER_H

using namespace std;

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


#endif