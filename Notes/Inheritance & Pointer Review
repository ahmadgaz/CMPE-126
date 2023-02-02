Inheritence & Pointer Review

class Animal {
public:
  virtual void makeNoise() = animal;
}

class Cat : public Animal {
public:
  void makeNoise() = meow;
  // Inherited from animal, contains makeNoise();
}


Animal a1;
a1.makeNoise();
Animal *aptr; // Creating a pointer
aptr = &a1; // Point it to the address of a1
a1->makeNoise(); // Calling a method of a pointer using arrow notation

Polymorphism:
Cat c1;
c1.makeNoise(); //  This calls the Cat classes method "makeNoise"
aptr = &c1; // This works because Cat is inherited from Animal, however it would not work if Cat was seperate

aptr->makeNoise(); // Since makeNoise() is virtual in Animal, it is a meow. Otherwise it would be animal

IF THERE IS A POINTER OF TYPE ANIMAL, BUT IT HAS AN ADDRESS OF A CAT, COMPILER LOOKS AT THE:
- TYPE OF POINTER (ANIMAL)
- ADDRESS INSIDE TO DETERMINE IF IT IS ADDRESS OF AN ANIMAL OR A CAT TO DECIDE WHICH MAKENOISE TO CALL

Animal *list[5];
push a Cat, Dog, Horse, Cat, Dog;
for(int i = 0; i < 5; i++) {
  list[i]->makeNoise(); // meow, woof, neigh, meow, woof
}
