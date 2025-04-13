#include "lexer.h"
// #include "someBuilders.hh"
namespace Core {
class Parser {
public:
  Parser();
  Parser(const Lexer &lexer);
  ASTNodePtr getAST();
  ASTNodePtr parse();

  ASTNodePtr buildUnaryOperator();
  ASTNodePtr buildBinaryOperator(ASTNodePtr left);
  ASTNodePtr buildTemaryOperator();

private:
};
} // namespace Core
