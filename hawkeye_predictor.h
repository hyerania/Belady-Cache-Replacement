#ifndef HAWKEYE_PREDICTOR_H
#define HAWKEYE_PREDICTOR_H

using namespace std;
#include <vector>
#include <map>
#include "helper_function.h"

#define MAX_PCMAP 31
#define PCMAP_SIZE 2048

class Hawkeye_Predictor{
private:
	map<uint64_t, int> PC_Map;

public:
	//Return prediction for PC Address
	bool get_prediction(uint64_t PC){
		uint64_t result = CRC(PC) % PCMAP_SIZE;
		if(PC_Map.find(result) != PC_Map.end() && PC_Map[result] < ((MAX_PCMAP+1)/2)){
			return false;
		}
		return true;
	}

	void increase(uint64_t PC){
		uint64_t result = CRC(PC) % PCMAP_SIZE;
		if(PC_Map.find(result) == PC_Map.end()){
			PC_Map[result] = (MAX_PCMAP + 1)/2;
		}

		if(PC_Map[result] < MAX_PCMAP){
			PC_Map[result] = PC_Map[result]+1;
		}
		else{
			PC_Map[result] = MAX_PCMAP;
		}
	}

	void decrease(uint64_t PC){
		uint64_t result = CRC(PC) % PCMAP_SIZE;
		if(PC_Map.find(result) == PC_Map.end()){
			PC_Map[result] = (MAX_PCMAP + 1)/2;
		}
		if(PC_Map[result] != 0){
			PC_Map[result] = PC_Map[result] - 1;
		}
	}

};

#endif