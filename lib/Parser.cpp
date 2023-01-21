#include "Parser.h"

namespace Sugar::Input{

void Parser::Parse(std::int32_t &destination, std::string_view input) {

  std::string _tmp(input);
  if(!std::regex_match(_tmp,signedNumberFilter))
    throw std::invalid_argument("Not a valid int");
  destination = std::stoi(_tmp);
}
void Parser::Parse(std::uint32_t &destination, std::string_view input)
{
  std::string _tmp(input);
  if(!std::regex_match(_tmp,unsignedNumberFilter))
    throw std::invalid_argument("Not a valid unsigned int");
  destination = std::stoul(_tmp);
}
void Parser::Parse(std::int64_t &destination, std::string_view input)
{
  std::string _tmp(input);
  if(!std::regex_match(_tmp,signedNumberFilter))
    throw std::invalid_argument("Not a valid long long");
  destination = std::stoll(_tmp);
}
void Parser::Parse(std::uint64_t &destination, std::string_view input)
{
  std::string _tmp(input);
  if(!std::regex_match(_tmp,unsignedNumberFilter))
    throw std::invalid_argument("Not a valid unsigned long long");
  destination = std::stoull(_tmp);
}
void Parser::Parse(std::string &destination, std::string_view input)
{
  std::string _tmp(input);
  for(auto& c : _tmp)
  {
      std::string tmp2 = "";
      tmp2+=c;
      char cresult;
      Parse(cresult, tmp2);
  }
  destination = _tmp;
}
void Parser::Parse(char& destination, std::string_view input)
{
  std::string _tmp(input);
  if (_tmp.length() > 1) {
    throw std::invalid_argument("Not a valid char");
  }
  if(_tmp[0] >= 127 || _tmp[0] < 0)
  {
    throw std::invalid_argument("Unsupported/Unknown character");
  }
  else
  {
    destination = _tmp[0];
  }
}
void Parser::Parse(float& destination, std::string_view input)
{
  std::string _tmp(input);
  if(!std::regex_match(_tmp,signedDecimalFilter))
    throw std::invalid_argument("Not a valid float");
  destination = std::stof(_tmp);
}
void Parser::Parse(double& destination, std::string_view input)
{
  std::string _tmp(input);
  if(!std::regex_match(_tmp,signedDecimalFilter))
    throw std::invalid_argument("Not a valid double");
  destination = std::stod(_tmp);
}
void Parser::Parse(UserIOStreamable& destination, raw_input input)
{
  destination.Parse(input);
}
}