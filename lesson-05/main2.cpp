
class Pound : Currency 
{
private:
    string abbreviation;
    double amount;
    
public:
Pound (string NewAbbreviation, float NewAmount)
{
    this -> amount = NewAmount;
    this -> abbreviation = NewAbbreviation;
}

string Abbreviation() const 
{
    return abbreviation;
}

double Amount () const 
{
    return amount;
}

double ConvertedToDollars(const Cantor& cantor) const 
{
    return amount / cantor.Rate(abbreviation);
}
    
};

int main() {
  FakeUsdCantor fake;
  Pound value("GBP", 250);
  cout << value.ConvertedToDollars(fake) << endl;

  return 0;
}
