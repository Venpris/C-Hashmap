#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

HashMap make_map(int initial_size) {
    HashMap map;

    map.entries = (char*)malloc(initial_size * sizeof(HashEntry*));

    for (int i = 0; i < initial_size; i++) { // Initialize the array of entries with null values
        map.entries[i] = NULL;
    }

    map.size = 0;
    map.capacity = initial_size;

    return map;
}

int hash(char* key) {
    unsigned int value = 0;
    int group_size = 4;

    // Use the folding method for the hashing function
    while (*key) {
        unsigned int group = 0;

        for (int i = 0; i < group_size && *key; i++) {
            group = (group << 8) + *key; // Bitwise shift left by 8 (int is 8 bits).
            // ^^ This is creating essentially a binary ASCII representation of the string, which can be modded by capacity to get an index
            key++;
        }

        value += group;
    }

    return value; // Need to take the modulus later, didn't do it in this function to allow for better refactoring later (dynamic resizing)
}

void put(HashMap* map, char* key, char* value) {
    int index = hash(key) % capacity;

    // Loop through the array until either an empty index is found or the end of the array is reached
    while (map->entries[index] != '\0') {
        if (map->entries[index] != NULL) {
            index++;
        } else {
            map->entries[index] = malloc(sizeof(HashEntry));

            // Make copies of the key and value strings
            map->entries[index]->key = strdup(key);
            map->entries[index]->value = strdup(value);
            break;
        }
    }
}