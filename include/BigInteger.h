#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace bigint
{

class BigInteger
{
public:

    // ---------- Constructors ----------

    BigInteger();

    BigInteger(long long value);

    explicit BigInteger(const std::string& value);

    BigInteger(const BigInteger&) = default;

    BigInteger(BigInteger&&) noexcept = default;

    BigInteger& operator=(const BigInteger&) = default;

    BigInteger& operator=(BigInteger&&) noexcept = default;

    ~BigInteger() = default;

    // ---------- Conversion ----------

    std::string toString() const;

    bool isZero() const;

    bool isNegative() const;

    BigInteger abs() const;

    // ---------- Arithmetic ----------

    BigInteger operator+(const BigInteger& rhs) const;

    BigInteger operator-(const BigInteger& rhs) const;

    BigInteger operator*(const BigInteger& rhs) const;

    BigInteger operator/(const BigInteger& rhs) const;

    BigInteger operator%(const BigInteger& rhs) const;

    BigInteger operator-() const;

    BigInteger& operator+=(const BigInteger& rhs);

    BigInteger& operator-=(const BigInteger& rhs);

    BigInteger& operator*=(const BigInteger& rhs);

    BigInteger& operator/=(const BigInteger& rhs);

    BigInteger& operator%=(const BigInteger& rhs);

    // ---------- Increment / Decrement ----------

    BigInteger& operator++();

    BigInteger operator++(int);

    BigInteger& operator--();

    BigInteger operator--(int);

    // ---------- Comparison ----------

    bool operator==(const BigInteger& rhs) const;

    bool operator!=(const BigInteger& rhs) const;

    bool operator<(const BigInteger& rhs) const;

    bool operator>(const BigInteger& rhs) const;

    bool operator<=(const BigInteger& rhs) const;

    bool operator>=(const BigInteger& rhs) const;

    // ---------- Stream ----------

    friend std::ostream& operator<<(std::ostream& out,
                                    const BigInteger& value);

    friend std::istream& operator>>(std::istream& in,
                                    BigInteger& value);

    // ---------- Utility ----------

    static BigInteger gcd(BigInteger a,
                          BigInteger b);

private:

    static constexpr int BASE = 1000000000;
    static constexpr int BASE_DIGITS = 9;
    static constexpr std::size_t KARATSUBA_THRESHOLD = 32;

    std::vector<int> digits;
    bool negative;

private:

    void trim();

    static int absCompare(const BigInteger& lhs,
                          const BigInteger& rhs);

    static BigInteger absAdd(const BigInteger& lhs,
                             const BigInteger& rhs);

    static BigInteger absSubtract(const BigInteger& lhs,
                                  const BigInteger& rhs);

    static BigInteger multiplyNaive(const BigInteger& lhs,
                                    const BigInteger& rhs);

    static BigInteger multiplyKaratsuba(const BigInteger& lhs,
                                        const BigInteger& rhs);

    static BigInteger divide(const BigInteger& dividend,
                             const BigInteger& divisor,
                             BigInteger& remainder);

    void read(const std::string& value);
};

} // namespace bigint
