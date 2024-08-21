#pragma once

#include <godot_cpp/classes/node.hpp>

namespace godot {

class FinderImpl : public Node
{
    GDCLASS(FinderImpl, Node);

protected:
	static void _bind_methods();
    bool is_instance_of(Variant a, Variant type);

public:

    FinderImpl();
    ~FinderImpl();

    void _ready() override;
    void _process(double delta) override;

    Node* find_child_by_type(Node* parent, String type);
    Array find_children_by_type(Node* parent, String type);
    Node* find_child_by_type_with_condition(Node* parent, String type, Callable condition);
    Array find_children_by_type_with_condition(Node* parent, String type, Callable condition);
    Node* find_child_by_name(Node* parent, String name);
    Array find_children_by_name(Node* parent, String name);
    bool is_children(Node* parent, Node* node);
    Node* get_root();
};

}