typedef struct {
    char* text; // Initialize to NULL
    int index; // The index where the key-value pair lies in the array, initialize to -1
} Key;

typedef struct {
    Key* key;
    char* value;
    } HashEntry;

typedef struct {
    HashEntry** entries;
    int size;
    int capacity;
    } HashMap;

/*
* Constructs an instance of the hashmap.
*
* @param initial_size Determines how many values the map will hold upon being created.
*
* @return An instance of a HashMap at the specified size.
*/
HashMap make_map(int initial_size); 

/*
* Creates a value using a hashing function involving the ASCII values of the key string.
*
* @param key The key for which the hash value is generated. Passed as a string.
*
* @return A hash value that can be modded with the capacity of the map to create
*         an index at which the key-value pair can be inserted.
*/
int hash(char* key);

/*
* Inserts a key-value pair into the HashMap.
*
* @param map A pointer to the map where the pair will be inserted.
* @param key The key in the key-value pair.
* @param value The value in the key-value pair.
*/
void put(HashMap* map, Key* key, char* value);

/*
* Retrieves the value associated with a specified key.
*
* @param map A pointer to the map containing the value associated with the key.
* @param key The key in the key-value pair.
*
* @return The value associated with the specified key in the map.
*/
char* get(HashMap* map, Key* key);

/*
* Removes a specified key-value pair from the map.
*
* @param map The map containing the specified key-value pair.
* @param key The key in the specified key-value pair.
*/
void map_remove(HashMap* map, Key* key);

/*
* Frees all memory allocated for the map and its entries, to be used when exiting the program or when the hashmap is no longer being used.
*
* @param map The map that memory has been allocated for.
*/
void free_map(HashMap* map);