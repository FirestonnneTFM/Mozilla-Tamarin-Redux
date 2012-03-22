package { 
    public function nextWeaker(val) {
        switch (val) {
            case 0: return 10;
            case 1: return 20;
            case 2: return 30;
            case 3: return 40;
            case 4: return 50;
            case 5: return 60;
        }
        // return a dummy val here to please compiler
        return 70;
    }

	for (var i = 0; i < 20; i++) {
		print(nextWeaker(3));
	}
    
} 

