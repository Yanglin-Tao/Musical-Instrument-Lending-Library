//
//  main.cpp
//  rec11
//
//  Created by Yanglin Tao on 11/12/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Instrument{
public:
    virtual void makeSound() const = 0;
    virtual void makeNormalSound() const = 0;
};

void Instrument::makeSound() const{
    cout << "To make a sound...";
}
class MILL{
public:
    void receiveInstr(Instrument& aInstr){
        aInstr.makeSound();
        for(size_t i = 0; i < vectorInstruments.size(); i++){
            if(vectorInstruments[i] == nullptr){
                vectorInstruments[i] = &aInstr;
                return;
            }
        }
        vectorInstruments.push_back(&aInstr);
    
    }
    
    Instrument* loanOut(){
        for(size_t i = 0; i < vectorInstruments.size(); i++){
            if(vectorInstruments[i] != nullptr){
                Instrument* address = vectorInstruments[i];
                vectorInstruments[i] = nullptr;
                return address;
            }
        }
        return nullptr;
    }
    
    void dailyTestPlay(){
        for(size_t i = 0; i < vectorInstruments.size(); i++){
            if(vectorInstruments[i] != nullptr){
                vectorInstruments[i] -> makeSound();
            }
        }
    }
    
private:
    vector<Instrument*> vectorInstruments;
};

// class Brass
class Brass : public Instrument{
public:
    Brass(unsigned size) : size(size){}
    void makeSound() const{
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << size << endl;
    }
private:
    unsigned size;
};

class Trumpet : public Brass{
public:
    Trumpet(unsigned size) : Brass(size){}
    void makeNormalSound() const{
        cout << "Toot";
    }
};

class Trombone : public Brass{
public:
    Trombone(unsigned size) : Brass(size){}
    void makeNormalSound() const{
        cout << "Blat";
    }
};

// class String
class String : public Instrument{
public:
    String(unsigned pitch) : pitch(pitch){}
    void makeSound() const{
        Instrument::makeSound();
        cout << "bow a string with pitch " << pitch << endl;
    }
private:
    unsigned pitch;
};

class Violin : public String{
public:
    Violin(unsigned pitch) : String(pitch){}
    void makeNormalSound() const{
        cout << "Screech";
    }

};

class Cello : public String{
public:
    Cello(unsigned pitch) : String(pitch){}
    void makeNormalSound() const{
        cout << "Squawk";
    }
};


// class Percussion
class Percussion : public Instrument{
public:
    // Percussion(){};
    void makeSound() const{
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }
};

class Drum : public Percussion{
public:
    // Drum() : Percussion(){};
    void makeNormalSound() const{
        cout << "Boom";
    }
    
};

class Cymbal : public Percussion{
public:
    // Cymbal() : Percussion(){};
    void makeNormalSound() const{
        cout << "Crash";
    }
};

class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }
    
    void normalPlay(){
        if (instr){
            instr->makeNormalSound();
        }
    }

private:
    Instrument* instr;
};

class Orch{
public:
    void addPlayer(Musician& aMusician){
        vectorMusicians.push_back(&aMusician);
    }
    
    void play(){
        for(size_t i = 0; i < vectorMusicians.size(); i++){
            vectorMusicians[i] -> normalPlay();
        }
        cout << endl;
    }
private:
    vector<Musician*> vectorMusicians;
};


int main() {

    //
    // PART ONE
    //
//    cout << "P A R T  O N E\n";
//
//    cout << "Define some instruments ----------------------------------------\n";
//     Drum drum;
//     Cello cello(673);
//     Cymbal cymbal;
//     Trombone tbone(4);
//     Trumpet trpt(12) ;
//     Violin violin(567) ;
//
//    // use the debugger to look at the mill
//    cout << "Define the MILL ------------------------------------------------\n";
//     MILL mill;
//
//    cout << "Put the instruments into the MILL ------------------------------\n";
//     mill.receiveInstr(trpt);
//     mill.receiveInstr(violin);
//     mill.receiveInstr(tbone);
//     mill.receiveInstr(drum);
//     mill.receiveInstr(cello);
//     mill.receiveInstr(cymbal);
//
//    cout << "Daily test -----------------------------------------------------\n"
//     << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//    cout << "Define some Musicians-------------------------------------------\n";
//     Musician harpo;
//     Musician groucho;
//
//     cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
//     groucho.testPlay();
//     cout << endl;
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << endl << endl;
//
//     groucho.testPlay();
//     cout << endl;
//     mill.receiveInstr(*groucho.giveBackInstr());
//     harpo.acceptInstr(mill.loanOut());
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     harpo.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
//
//     // fifth
//     mill.receiveInstr(*groucho.giveBackInstr());
//     cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
//     mill.receiveInstr(*harpo.giveBackInstr());
//
//
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << endl;


    //
    // PART TWO
    //
    
   
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

}

