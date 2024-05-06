#ifndef CITERATOR_HPP
#define CITERATOR_HPP

#include "AVLTree.hpp"

template<typename Key, typename Value, typename Comp>
class ConstIterator
{
  friend class AVLTree;
public:
  using Node = TreeNode<Key, Value>;

  ConstIterator(Node* node):
    current_(node)
  {}

  const std::pair<const Key, Value>& operator*() const
  {
    return current_->data;
  }

  const std::pair<const Key, Value>* operator->() const
  {
    return &(current_->data);
  }

  ConstIterator& operator++()
  {
    if (current_ == nullptr)
    {
      return *this;
    }
    if (current_->right != nullptr)
    {
      current_ = current_->right;
      while (current_->left != nullptr)
      {
        current_ = current_->left;
      }
    }
    else
    {
      Node* prev;
      do
      {
        prev = current_;
        current_ = current_->parent;
      } while (current_ != nullptr && prev == current_->right);
    }
    return *this;
  }

  ConstIterator operator++(int)
  {
    ConstIterator tmp = *this;
    ++(*this);
    return tmp;
  }

  bool operator==(const ConstIterator& other) const
  {
    return current_ == other.current_;
  }

  bool operator!=(const ConstIterator& other) const
  {
    return !(*this == other);
  }

private:
  Node* current_;
};

#endif
