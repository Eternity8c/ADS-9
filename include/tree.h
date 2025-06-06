// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <memory>

struct Node {
    char val;
    std::vector<std::unique_ptr<Node>> childNodes;
    explicit Node(char v) : val(v) {}
};

class PermutationTree {
 private:
    std::vector<std::unique_ptr<Node>> rootNodes;
    std::vector<char> symbolSet;
    
    void buildPermutationTree(Node* currentNode, std::vector<char> remainingSymbols);
    bool findPermutationByNumber(Node* node, int& counter, std::vector<char>& currentPerm,
                               std::vector<char>& resultPerm, int level);

 public:
    explicit PermutationTree(const std::vector<char>& inputSet);
    ~PermutationTree() = default;
    
    void collectAllPermutations(Node* node, std::vector<char>& currentPath,
                              std::vector<std::vector<char>>& allPermutations);
    
    const std::vector<std::unique_ptr<Node>>& getRootNodes() const {
        return rootNodes;
    }
    
    const std::vector<char>& getSymbolSet() const {
        return symbolSet;
    }
};

std::vector<std::vector<char>> getAllPossiblePermutations(const PermutationTree& tree);
std::vector<char> getPermutationByIndex1(const PermutationTree& tree, int index);
std::vector<char> getPermutationByIndex2(const PermutationTree& tree, int index);
#endif  // INCLUDE_TREE_H_
