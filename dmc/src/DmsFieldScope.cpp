#include "DmsFieldScope.h"

DmsFieldScope::DmsFieldScope()
        : enclosing_scope(nullptr) {
}

DmsFieldScope::~DmsFieldScope() {
}

void DmsFieldScope::set_enclosing_scope(DmsFieldScope *enclosing_scope_) {
    enclosing_scope = enclosing_scope_;
}

void DmsFieldScope::set_field_value(std::string name, int value) {
    std::map<std::string, DmsField<int>>::iterator it = int_fields.find(name);

    if (it != int_fields.end()) {
        it->second.set_value(value);
    } else {
        int_fields[name] = DmsField<int>(name, value);
    }
}

void DmsFieldScope::set_field_value(std::string name, float value) {
    std::map<std::string, DmsField<float>>::iterator it = float_fields.find(name);

    if (it != float_fields.end()) {
        it->second.set_value(value);
    } else {
        float_fields[name] = DmsField<float>(name, value);
    }
}

void DmsFieldScope::set_field_value(std::string name, std::string value) {
    std::map<std::string,DmsField<std::string>>::iterator it = string_fields.find(name);

    if (it != string_fields.end()) {
        it->second.set_value(value);
    } else {
        string_fields[name] = DmsField<std::string>(name, value);
    }
}

std::vector<std::string> DmsFieldScope::get_all_field_names() {
    std::vector<std::string> result;

    for (const auto a : int_fields) {
        result.push_back(a.first);
    }
    for (const auto a : float_fields) {
        result.push_back(a.first);
    }
    for (const auto a : string_fields) {
        result.push_back(a.first);
    }

    return result;
}

std::string DmsFieldScope::serialize() {
    std::string result = "";

    for (auto a : int_fields) {
        result += a.second.serialize();
    }
    for (auto a : float_fields) {
        result += a.second.serialize();
    }
    for (auto a : string_fields) {
        result += a.second.serialize();
    }

    return result;
}

std::string DmsFieldScope::compile() {
    std::string result = "";

    for (auto a : int_fields) {
        result += a.second.compile();
    }
    for (auto a : float_fields) {
        result += a.second.compile();
    }
    for (auto a : string_fields) {
        result += a.second.compile();
    }

    return result;
}
