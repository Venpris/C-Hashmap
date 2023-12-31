# C-Hashmap
Hashmap implementation in C

This is a version of Java's HashMap implementation written in C. With
this project, I'm hoping to deepen my understanding of data structures
and how they function on a lower level.

UPDATES:
- 10/3/2023: This is the start. I actually found out earlier that my understanding of hashmaps on a fundamental level is spotty, at best. After spending a lot of time researching, I feel much more confident that I can finish this project. For now, I simply want some way to create a very barebones implementation of a hashmap to where I have functioning key/value pairs, then I'll go from there with the remaining functions (put, remove, etc etc.)

- 10/8/2023: I'm now able to create and hash a hash table, which is pretty good. The put function still isn't fully working yet, but I'm planning on getting that sorted out soon. I wrote some unit tests (for the first time in C as well!) and now I want to use the debugger to hopefully get all 3 tests passing, but I'm still having a little trouble setting that up.

- 10/9/2023: Finally fixed the code for the put function. I struggled for a while to implement the get function today (segmentation faults during testing) but eventually managed it. I also realized that I needed a structure for the keys in order to maintain O(1) time complexity (or rather it was the easiest way to do so without needing to call the hash function and retrieve an index in every other API function), so I had the key structure store an integer representing the index where the key-value pair was stored in the map. I spent some time rewriting all of my code to work with this change, but I think it was worth it as it makes other functions (such as get) much easier to implement.

- 10/10/2023: Finished a simple implementation of the map! For now, it just works with strings and only supports basic API functions. I might come back at a later date to implement the changes below.

TODO:
    - 

In the future I'm hoping to add more features to this hashmap, such as:
- Dynamic sizing
- Generic implementation

Written in C on Visual Studio Code Community Edition and uses Unity v2.5.2
for unit tests:
https://github.com/ThrowTheSwitch/Unity/releases/tag/v2.5.2
