typedef struct {
    char* key;
    char* value;
    } HashEntry;

typedef struct {
    HashEntry* entries;
    int size;
    int capacity;
    } HashMap;

HashMap make_map(int initial_size); // Constructor for the map

int hash(char* key);