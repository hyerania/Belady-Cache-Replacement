# Cache Repalcement Improvement on Last-Level Caches
Using Belady's algorithm for improved cache replacement policy
## Setup Instructions
- Setup Oracle VM VirtualBox for Ubuntu 18.10 (or latest version) on your local machine
- Setup Champsim simulator by following GitHub ChampSim repo instructions.
  ```
  git clone https://github.com/ChampSim/ChampSim.git
  ```
  However, in our implmementation we used a variation of ChampSim that was provided for 2nd Cache Replacement Championship. It can be found in the following [website link](https://www.dropbox.com/s/o6ct9p7ekkxaoz4/ChampSim_CRC2_ver2.0.tar.gz?dl=1).
- Clone the current repository that contains the Hawkeye implementation using the following command:
  ```
  git clone https://github.com/hyerania/BeladyCacheReplacement.git
  ```

## Running Hawkeye for Single Core
- For configurations 1 and 2 (single-core simulation) from CRC2:
  - Compile code using the following command:
    ```
    g++ -Wall --std=c++11 -o lru-config1 example/hawkeye_algorithm.cc lib/config1.a
    g++ -Wall --std=c++11 -o lru-config2 example/hawkeye_algorithm.cc lib/config2.a
    ```
  - To run the simulation, use the following command, where the NUM_INSTRUCTIONS and FILE_NAME are replaced with proper parameters:
    ```
    ./lru-config1 -warmup_instructions NUM_INSTRUCTIONS -simulation instructions NUM_INSTRUCTIONS -traces trace/FILE_NAME.trace.gz
    ```
