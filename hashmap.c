#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

HashMap make_map(int initial_size) {
    HashMap map;

    map.entries = (HashEntry**)malloc(initial_size * sizeof(HashEntry*));

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
            group = (group << 8) + *key; // Bitwise shift left by 8 (char is 8 bits).
            // ^^ This is creating essentially a binary ASCII representation of the string, which can be modded by capacity to get an index
            key++;
        }

        value += group;
    }

    return value; // Need to take the modulus later, didn't do it in this function to allow for better refactoring later (dynamic resizing)
}

void put(HashMap* map, Key* key, char* value) {
    int index = hash(key->text) % map->capacity;
    int i = index;

    // Loop through the array until either an empty index is found or array is full
    do {
        // Check if spot is empty or occupying key is the same
        if (map->entries[i] == NULL || strcmp(map->entries[i]->key->text, key->text) == 0) {
            if (map->entries[i] == NULL) {
                map->entries[i] = malloc(sizeof(HashEntry));
                map->entries[i]->key = malloc(sizeof(Key)); // Allocate memory for key inside entry

                // Make copies of the key and value strings and insert at the index
                map->entries[i]->key->text = strdup(key->text);
                map->entries[i]->value = strdup(value);
            } else { // Replace existing value
                free(map->entries[i]->value);

                // Set new value
                map->entries[i]->value = strdup(value);
            }

            map->size++; // Increment size
            key->index = i; // Set key index to value at which key-value pair was inserted
            return;
        }

        i = (i + 1) % map->capacity;
    } while (i != index); // Allows to wrap back around when end of array is reached

    fprintf(stderr, "Map is full.\n");
}

char* get(HashMap* map, Key* key) {
    if (key->index == -1 || map->entries[key->index] == NULL) {
        fprintf(stderr, "Key-value pair does not exist in the map.\n");
        return NULL;
    } else {
        return map->entries[key->index]->value;
    }
}

void map_remove(HashMap* map, Key* key) {
    if (key->index == -1 || map->entries[key->index] == NULL) {
        fprintf(stderr, "Key-value pair does not exist in the map.\n");
    } else {
        // Free memory
        free(map->entries[key->index]->key);
        free(map->entries[key->index]->value);
        
        // Reset values and decrement size
        map->entries[key->index] = NULL;
        map->size--;
        key->index = -1;
    }
}

void free_map(HashMap* map) {
    // Free entries
    for (int i = 0; i < map->capacity; i++) {
        if (map->entries[i] != NULL) {
            free(map->entries[i]->key);
            free(map->entries[i]->value);
        }
    }

    free(map);
}