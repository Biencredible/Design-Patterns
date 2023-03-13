/**
 * Takes a string stream and creates token stream.
*/
class Scanner
{
public:
    Scanner(istream&);
    virtual ~Scanner();
    virtual Token& Scan();

private:
    istream& _inputStream;
};
