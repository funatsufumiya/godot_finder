#pragma once

#include <godot_cpp/classes/node.hpp>
// #include <godot_cpp/core/class_db.hpp>

// # class_name FinderImpl
// extends Node

// @onready var GameRoot = get_node("/root/GameRoot")
// @onready var started_time_usec = Time.get_ticks_usec()

// func find_by_type(parent, type):
// 	if parent == null:
// 		push_warning("find_by_type: parent is null")
// 		return null
// 	for child in parent.get_children():
// 		if is_instance_of(child, type):
// 			return child
// 		var grandchild = find_by_type(child, type)
// 		if grandchild != null:
// 			return grandchild
// 	return null
	
// func find_all_by_type(parent, type):
// 	if parent == null:
// 		push_warning("find_all_by_type: parent is null")
// 		return []
// 	var result = []
// 	for child in parent.get_children():
// 		if is_instance_of(child, type):
// 			result.append(child)
// 		var grandchilds = find_all_by_type(child, type)
// 		for grandchild in grandchilds:
// 			result.append(grandchild)
// 	return result

// func find_all_by_type_with_condition(parent, type, condition):
// 	var all = find_all_by_type(parent, type)
// 	var result = []
// 	for item in all:
// 		if condition.call(item):
// 			result.append(item)
// 	return result

// func find_by_type_with_condition(parent, type, condition):
// 	var all_with_cond = find_all_by_type_with_condition(parent, type, condition)
// 	if len(all_with_cond) > 0:
// 		return all_with_cond[0]
// 	return null

// func find_child_by_name(parent, name):
// 	if parent == null:
// 		push_warning("find_child_by_name: parent is null")
// 		return null
// 	for child in parent.get_children():
// 		if child.get_name() == name:
// 			return child
// 		var grandchild = find_child_by_name(child, name)
// 		if grandchild != null:
// 			return grandchild
// 	return null

// func find_all_children_by_name(parent, name):
// 	if parent == null:
// 		push_warning("find_all_children_by_name: parent is null")
// 		return []
// 	var result = []
// 	for child in parent.get_children():
// 		if child.get_name() == name:
// 			result.append(child)
// 		var grandchilds = find_all_children_by_name(child, name)
// 		for grandchild in grandchilds:
// 			result.append(grandchild)
// 	return result

// func is_children(parent, node):
// 	if parent == null:
// 		push_warning("is_children: parent is null")
// 		return false
// 	for child in parent.get_children():
// 		if child == node:
// 			return true
// 		if is_children(child, node):
// 			return true
// 	return false
	
// func get_root():
// 	return GameRoot



namespace godot {

class FinderImpl : public Node
{
    GDCLASS(FinderImpl, Node);

protected:
	static void _bind_methods();

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