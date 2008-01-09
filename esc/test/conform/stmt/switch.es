switch (10) {
case 5:
    print("WRONG");
case 10:
    print("RIGHT 10");
    // fall through
case 20:
    print("RIGHT 20");
    break;
}

switch (10) {
case 5:
    print("WRONG");
}

switch (10) {
case 5:
    print("WRONG");
default:
    print("RIGHT default");
    break;
case 8:
    print("WRONG");
}

print("DONE");
