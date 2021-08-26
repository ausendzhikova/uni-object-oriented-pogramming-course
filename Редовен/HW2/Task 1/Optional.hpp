#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template <typename T>

class Optional {
private:
    T* ptrValue;
public:
    Optional();
    Optional(const T& value);
    Optional(const Optional& other);
    Optional& operator=(const Optional& rhs);

    bool is_none() const;
    T get_value() const;

    ~Optional();
};

template<typename T>
inline Optional<T>::Optional() {
    ptrValue = nullptr;
}

template<typename T>
inline Optional<T>::Optional(const T& value) {
    ptrValue = new T(value);
}

template<typename T>
inline Optional<T>::Optional(const Optional& other) {
    ptrValue = other.ptrValue ? new T(*other.ptrValue) : nullptr;
}

template<typename T>
inline Optional<T>& Optional<T>::operator=(const Optional& rhs) {
    if (this != &rhs) {
        delete ptrValue;
        ptrValue = rhs.ptrValue ? new T(*rhs.ptrValue) : nullptr;
   }
    return *this;
}

template<typename T>
inline bool Optional<T>::is_none() const {
    if (ptrValue == nullptr) {
        return true;
    }
    return false;
}

template<typename T>
inline T Optional<T>::get_value() const {
    if (is_none()) {
        return T();
    }
    return *ptrValue;
}

template<typename T>
inline Optional<T>::~Optional() {
    delete ptrValue;
}
