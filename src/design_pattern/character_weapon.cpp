#include <iostream>
#include <memory>
using namespace std;

class Weapon{
public:
  virtual void Attack() = 0;
  //If the destructor is pure function
  //we need to provide a definition for it!!
  virtual ~Weapon() = 0;
  //virtual ~Weapon(){cout<<"Weapon Destructor"<<endl;};
};
//This is needed if the destructor is defined as a pure function
Weapon::~Weapon(){}

class Axe : public Weapon{
public:
  void Attack() override{
    cout<<"Axe Attack"<<endl;
  }
  ~Axe(){cout<<"Axe destructor"<<endl;}
};

class Sword : public Weapon{
public:
  void Attack() override{
    cout<<"Sword Attack"<<endl;
  }
  ~Sword(){cout<<"Sword destructor"<<endl;}
};

class Character{
public:
  virtual ~Character(){cout<<"Character Destructor"<<endl;}
  void SetWeapon(unique_ptr<Weapon> w){
    m_weapon = move(w);
  }
  bool HasWeapon(){
    return m_weapon != nullptr;
  }
  virtual void Fight() = 0;
  void Attack(){
    if(m_weapon){
      m_weapon->Attack();
    }
  }
private:
  unique_ptr<Weapon> m_weapon;
};

class Knight : public Character{
public:
  void Fight() override{
    cout<<"I am a Knight"<<endl;
    if(HasWeapon()){
      cout<<"I will fight"<<endl;
      Attack();
    }else{
      cout<<"I don't have weapon"<<endl;
      cout<<"Please I need a weapon before I can fight"<<endl;
    }
  }
};

unique_ptr<Knight> CreateKnight(){
  return unique_ptr<Knight>(new Knight());
}
void Character_Weapon_Test(){
  unique_ptr<Character> knight = CreateKnight();
  knight->Fight();
  knight->SetWeapon(unique_ptr<Weapon>(new Sword()));
  knight->Fight();
  knight->Fight();
  knight->SetWeapon(unique_ptr<Weapon>(new Axe()));
  knight->Fight();
}
  


