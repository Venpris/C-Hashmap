typedef struct {
    char* key;
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
* @param key The key for which the hash value is generated. Must be a string.
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
void put(HashMap* map, char* key, char* value);

char* get(HashMap* map, char* key);

void map_remove(HashMap* map, char* key);