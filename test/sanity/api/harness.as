package {
  // t = test function
  // e = error expected
  var run_count = 0;
  public function run(t,e) {
    var r;
    var m = "";
    try {
      r = t()
      if (e) {
        m = ": error expected";
        r = false;
      }
    } catch (x) {
      r = e;
      if (!e) {
         m = ": unexpected error: " + x;
         r = false;
      }
    }
    finally {
      print("[" + run_count++ + "] " + r + m);
    }
  }
}