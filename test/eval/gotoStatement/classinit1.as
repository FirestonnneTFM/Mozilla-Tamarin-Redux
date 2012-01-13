class C {
	print("hi");
	goto L1;
	static var x = 20;
L1: print("ho: " + x);
};
(new C);
