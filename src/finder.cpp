#include "finder.hpp"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/script.hpp>

#include <memory>

using namespace godot;

void FinderImpl::_bind_methods() {
    // ClassDB::bind_method(D_METHOD("_init", "inPort", "outPort", "outIP"), &OSC::_init);
    // ClassDB::bind_static_method("FinderImpl", D_METHOD("create", "inPort", "outPort", "outIP"), &OSC::create);

    ClassDB::bind_method(D_METHOD("find_child_by_type", "parent", "typeName"), &FinderImpl::find_child_by_type);
    ClassDB::bind_method(D_METHOD("find_children_by_type", "parent", "typeName"), &FinderImpl::find_children_by_type);
    ClassDB::bind_method(D_METHOD("find_child_by_type_with_condition", "parent", "typeName", "condition"), &FinderImpl::find_child_by_type_with_condition);
    ClassDB::bind_method(D_METHOD("find_children_by_type_with_condition", "parent", "typeName", "condition"), &FinderImpl::find_children_by_type_with_condition);
    ClassDB::bind_method(D_METHOD("find_child_by_name", "parent", "name"), &FinderImpl::find_child_by_name);
    ClassDB::bind_method(D_METHOD("find_children_by_name", "parent", "name"), &FinderImpl::find_children_by_name);
    ClassDB::bind_method(D_METHOD("is_children", "parent", "node"), &FinderImpl::is_children);
    ClassDB::bind_method(D_METHOD("get_root"), &FinderImpl::get_root);
}

bool FinderImpl::is_instance_of(Variant a, String typeName)
{
    // first, check GDNativeClass
    Object *value_object = Object::cast_to<Object>(a);
    bool res = ClassDB::is_parent_class(value_object->get_class(), typeName);

    if(res) {
        return res;
    }

    // second, check Script
    if (value_object->get_script()) {
        Variant script = value_object->get_script();
        Script *script_ptr = Object::cast_to<Script>(script);
        while (script_ptr) {
            // NOTE: this causes wrong results!!
            // if (script_ptr->instance_has(value_object)) {
            //     UtilityFunctions::print(a.operator String() + " is instance of " + typeName + " by script");
            //     return true;
            // }
            if (script_ptr->get_global_name() == typeName) {
                // UtilityFunctions::print(a.operator String() + " is instance of " + typeName + " by script");
                return true;
            }
            else if (script_ptr->get_instance_base_type() == typeName) {
                // UtilityFunctions::print(a.operator String() + " is instance of " + typeName + " by script");
                return true;
            }
            else{
                script_ptr = script_ptr->get_base_script().ptr();
            }
        }
    }

    return false;
}

FinderImpl::FinderImpl()
{
    // UtilityFunctions::print("FinderImpl::constructor");
}

FinderImpl::~FinderImpl()
{
}

void FinderImpl::_ready()
{
    // UtilityFunctions::print("FinderImpl::_ready");
}

void FinderImpl::_process(double delta)
{
    // UtilityFunctions::print("FinderImpl::_process");
}

// Node* find_child_by_type(Node* parent, String type);
//     Array find_children_by_type(Node* parent, String type);
//     Node* find_child_by_type_with_condition(Node* parent, String type, Callable condition);
//     Array find_children_by_type_with_condition(Node* parent, String type, Callable condition);
//     Node* find_child_by_name(Node* parent, String name);
//     Array find_children_by_name(Node* parent, String name);
//     bool is_children(Node* parent, Node* node);
//     Node* get_root();

Node* FinderImpl::find_child_by_type(Node* parent, String typeName)
{
    if (parent == nullptr)
    {
        UtilityFunctions::push_warning("find_child_by_type: parent is null");
        return nullptr;
    }
    for (int i = 0; i < parent->get_child_count(); i++)
    {
        Node* child = parent->get_child(i);
        if(is_instance_of(child, typeName))
        {
            return child;
        }
        Node* grandchild = find_child_by_type(child, typeName);
        if (grandchild != nullptr)
        {
            return grandchild;
        }
    }
    return nullptr;
}

Array FinderImpl::find_children_by_type(Node* parent, String typeName)
{
    Array result;
    if (parent == nullptr)
    {
        UtilityFunctions::push_warning("find_children_by_type: parent is null");
        return result;
    }
    for (int i = 0; i < parent->get_child_count(); i++)
    {
        Node* child = parent->get_child(i);
        if(is_instance_of(child, typeName))
        {
            result.append(child);
        }
        Array grandchilds = find_children_by_type(child, typeName);
        for (int j = 0; j < grandchilds.size(); j++)
        {
            result.append(grandchilds[j]);
        }
    }
    return result;
}

Node* FinderImpl::find_child_by_type_with_condition(Node* parent, String typeName, Callable condition)
{
    Array children = find_children_by_type(parent, typeName);
    Array result;
    for (int i = 0; i < children.size(); i++)
    {
        Variant v = children[i];
        Node* child = Object::cast_to<Node>(v);
        if (condition.call(child))
        {
            return child;
        }
    }
    return nullptr;
}

Array FinderImpl::find_children_by_type_with_condition(Node* parent, String typeName, Callable condition)
{
    Array children = find_children_by_type(parent, typeName);
    Array result;
    for (int i = 0; i < children.size(); i++)
    {
        Variant v = children[i];
        Node* child = Object::cast_to<Node>(v);
        if (condition.call(child))
        {
            result.append(child);
        }
    }
    return result;
}

Node* FinderImpl::find_child_by_name(Node* parent, String name)
{
    if (parent == nullptr)
    {
        UtilityFunctions::push_warning("find_child_by_name: parent is null");
        return nullptr;
    }
    for (int i = 0; i < parent->get_child_count(); i++)
    {
        Node* child = parent->get_child(i);
        if (child->get_name() == name)
        {
            return child;
        }
        Node* grandchild = find_child_by_name(child, name);
        if (grandchild != nullptr)
        {
            return grandchild;
        }
    }
    return nullptr;
}

Array FinderImpl::find_children_by_name(Node* parent, String name)
{
    Array result;
    if (parent == nullptr)
    {
        UtilityFunctions::push_warning("find_children_by_name: parent is null");
        return result;
    }
    for (int i = 0; i < parent->get_child_count(); i++)
    {
        Node* child = parent->get_child(i);
        if (child->get_name() == name)
        {
            result.append(child);
        }
        Array grandchilds = find_children_by_name(child, name);
        for (int j = 0; j < grandchilds.size(); j++)
        {
            result.append(grandchilds[j]);
        }
    }
    return result;
}

bool FinderImpl::is_children(Node* parent, Node* node)
{
    if (parent == nullptr)
    {
        UtilityFunctions::push_warning("is_children: parent is null");
        return false;
    }
    for (int i = 0; i < parent->get_child_count(); i++)
    {
        Node* child = parent->get_child(i);
        if (child == node)
        {
            return true;
        }
        if (is_children(child, node))
        {
            return true;
        }
    }
    return false;
}

Node* FinderImpl::get_root()
{
    // NOTE: returns the last child of the root node
    return get_tree()->get_root()->get_child(get_tree()->get_root()->get_child_count() - 1);
}