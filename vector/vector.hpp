#ifndef DS_VECTOR_HPP
#define DS_VECTOR_HPP 1

#include <cstddef>
#include <memory>
#include <algorithm>
#include <stdexcept>

namespace ds {
  template <typename T>
  class vector {
    std::size_t m_size;
    std::size_t m_capacity;
    std::unique_ptr<T[]> m_data;
  public:
    explicit vector(const std::size_t count = 0) : m_size(count), m_capacity(count), m_data(std::make_unique<T[]>(m_capacity)) {
    }
    vector(vector const &other) : m_size(other.m_size), m_capacity(other.m_capacity) {
      m_data = std::make_unique<T[]>(other.m_capacity);
      std::copy_n(other.m_data, other.m_size, m_data);
    }
    friend void swap(vector &v1, vector &v2) {
      std::swap(v1.m_size, v2.m_size);
      std::swap(v1.m_capacity, v2.m_capacity);
      std::swap(v1.m_data, v2.m_data);
    }
    vector& operator=(vector other) {
      swap(*this, other);
      return *this;
    }
    std::size_t size() const noexcept {
      return m_size;
    }
    T& operator[](const std::size_t index) {
      if (index >= m_size)
	throw std::out_of_range("Index out of range");
      return m_data[index];
    }
    T const& operator[](const std::size_t index) const {
      if (index >= m_size)
	throw std::out_of_range("Index out of range");
      return m_data[index];
    }
    void resize(const std::size_t count) {
      if (count > m_capacity) {
	m_capacity = count;
	std::unique_ptr<T[]> temp = std::make_unique<T[]>(count);
	std::copy_n(m_data, m_size, temp);
	m_data = temp;
      }
      m_size = count;
    }
  };
}

#endif //DS_VECTOR_HPP
