#include <iostream>
#include <memory>
#include <sstream>
#include <cassert>

using namespace std;

class Sequence {
public:
    virtual int Length()= 0;
    class Fake;
};

class Sequence::Fake: public Sequence {
public:
    int Length() override {return 100;}
};

class Gene {
private:
    std::string name_;
    std::shared_ptr<Sequence> seq_;

public:
    Gene(std::string name,std::shared_ptr<Sequence>seq):seq_(seq),name_(name){};


std::string JSON()const {


std::stringstream ss;
ss<< "{";
ss<< "\"name\": \""<<name_<<"\",";
ss<<"\length\": "<<seq_->Length();
ss<<"}";
return ss.str();
}


};

int main()
{
std::shared_ptr<Sequence::Fake> fakeSeq = std::make_shared<Sequence::Fake>();

Gene gene("BAFT5",fakeSeq);
std::cout<<gene.JSON();
    return 0;
}
