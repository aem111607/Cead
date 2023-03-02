#include "include/cs_array.h"

Byml* ArrayGet(Byml::Array* array, int index) {
    return &array->at(index);
}

void ArraySet(Byml::Array* array, int index, Byml* value) {
    array->assign(index, *value);
}

void ArrayAdd(Byml::Array* array, Byml* value) {
    array->push_back(*value);
}

void ArrayRemove(Byml::Array* array, int index) {
    array->erase(array->begin() + index);
}

void ArrayClear(Byml::Array* array) {
    array->clear();
}

int ArrayLength(Byml::Array* array) {
    return array->size();
}

Byml* ArrayCurrent(Byml::Array* array, int index) {
    return &array->at(index);
}

Byml::Array* BuildEmptyArray() {
    return new Byml::Array{};
}

Byml::Array* BuildArray(Byml** value, u32 value_len) {
    Byml::Array* byml_array = new Byml::Array(value_len);
    Byml* ptr = byml_array->data();
    for (size_t i = 0; i < value_len; i++) {
        *ptr = **value;
        ++ptr;
        ++value;
    }

    return byml_array;
}

// Byml::Array* BuildArray(Byml** value, u32 value_len) {
//     try {
//         for (size_t i = 0; i < value_len; i++) {
//             std::cout << "[c++] " << value[i]->GetString() << std::endl;
//         }
//
//         std::cout << "[c++] " << (*(value + value_len - 1))->GetString() << std::endl;
//         return new Byml::Array{*value, *(value + value_len - 1)};
//     } catch (const std::exception& exc) {
//         std::cerr << "[c++] " << exc.what() << std::endl;
//     }
//
//     return new Byml::Array{};
// `}