#include <string>
class CPerson
{
  private:
    std::string FirstName;
    std::string LastName;

  public:
    CPerson();
    CPerson(std::string firstName, std::string lastName);
    ~CPerson();
    std::string GetFirstName();
    void SetFirstName(std::string firstName);
    std::string GetLastName();
    void SetLastName(std::string lastName);
    std::string GetFullName();
    int GetInstanceSize();
};