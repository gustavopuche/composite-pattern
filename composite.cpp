#include "composite.h"

int main() {
  std::shared_ptr<Component> simple = std::make_shared<Leaf>();
  std::cout << "Client: I've got a simple component:\n";
  ClientCode(simple);
  std::cout << "\n\n";
  /**
   * ...as well as the complex composites.
   */

  std::shared_ptr<Component> tree = std::make_shared<Composite>();
  std::shared_ptr<Component> branch1 = std::make_shared<Composite>();

  std::shared_ptr<Component> leaf_1 = std::make_shared<Leaf>();
  std::shared_ptr<Component> leaf_2 = std::make_shared<Leaf>();
  std::shared_ptr<Component> leaf_3 = std::make_shared<Leaf>();
  branch1->Add(leaf_1);
  branch1->Add(leaf_2);
  std::shared_ptr<Component> branch2 = std::make_shared<Composite>();
  branch2->Add(leaf_3);
  tree->Add(branch1);
  tree->Add(branch2);
  std::cout << "Client: Now I've got a composite tree:\n";
  ClientCode(tree);
  std::cout << "\n\n";

  std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
  ClientCode2(tree, simple);
  std::cout << "\n";

  return 0;
}
