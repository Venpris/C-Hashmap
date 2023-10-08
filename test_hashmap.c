#include "unity/unity.h"
#include "hashmap.h"

void setUp() { }

void tearDown() { }

void test_make_map() {
    int initial_size = 10;
    HashMap map = make_map(initial_size);
    TEST_ASSERT_EQUAL_INT(0, map.size);
    TEST_ASSERT_EQUAL_INT(initial_size, map.capacity);
    for (int i = 0; i < initial_size; i++) {
        TEST_ASSERT_NULL(map.entries[i]);
    }
}

void test_hash() {
    char* key1 = "ababa";
    char* key2 = "key2";
    unsigned int hash1 = hash(key1);
    unsigned int hash2 = hash(key2);

    //Theoretically since the strings are different I'm hoping it avoids a collision here
    TEST_ASSERT_NOT_EQUAL(hash1, hash2);
}

void test_put() {
    HashMap map = make_map(10);

    char* key = "key";
    char* value = "value";

    put(&map, key, value);

    int index = hash(key) % map.capacity;
    TEST_ASSERT_NOT_NULL(map.entries[index]);
    TEST_ASSERT_EQUAL_STRING(key, map.entries[index]->key);
    TEST_ASSERT_EQUAL_STRING(value, map.entries[index]->value);
}

int main(void) {
    UnityBegin("test_hashmap.c");

    RUN_TEST(test_make_map);
    RUN_TEST(test_hash);
    RUN_TEST(test_put);

    return UnityEnd();
}