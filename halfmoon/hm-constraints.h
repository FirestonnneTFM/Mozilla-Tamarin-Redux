namespace halfmoon {

/// Range
///
template<typename T>
struct Range {
  const T x, y;
  Range(const T x, const T y) : x(x), y(y) {}
  T extent() { return y - x + 1; }
  bool empty() { return x > y; }
  bool contains(const T v) const { return v >= x && v <= y; }
  bool contains(const Range<T>& r) const { return r.x >= x && r.y <= y; }
  bool disjoint(const T v) const { return v < x || v > y; }
  bool disjoint(const Range<T>& r) const { return r.y < x || r.x > y; }
  bool operator==(const Range<T>& r) const { return r.x == x && r.y == y; }
  bool operator!=(const Range<T>& r) const { return *this != r; }
  Range<T> join(const Range<T>& r) const { return Range<T>(min(x, r.x), max(y, r.y)); }
  Range<T> meet(const Range<T>& r) const { return Range<T>(max(x, r.x), min(y, r.y)); }
};

/// RangeConstraint
///
template<typename T>
class RangeConstraint {
  RangeConstraint(const T min, const T max, bool sense) :
    r(min, max), sense(sense) {}

public:
  const Range<T> r;
  const bool sense;

  RangeConstraint<T> operator!() const {
    return RangeConstraint<T>(r.x, r.y, !sense);
  }

  // (v in w..x) -> (v in y..z) iff (w..x in y..z)
  // !(v in w..x) -> !(v in y..z) iff (y..z in w..x)
  // (v in w..x) -> !(v in y..z) iff disjoint(w..x, y..z)
  bool implies(const RangeConstraint<T>& rc) const {
    return (sense == rc.sense) ?
        (sense ? rc.r.contains(r) : r.contains(rc.r)) :
        (sense && r.disjoint(rc.r));
  }

  static RangeConstraint<T> eq(const T x) { return RangeConstraint<T>(x, x, true); }
  static RangeConstraint<T> in(const T x, const T y) { return RangeConstraint<T>(x, y, true); }
};

#ifdef DEBUG
void testRangeConstraints();
#endif

}
