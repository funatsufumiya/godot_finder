@tool
extends EditorPlugin

func _enter_tree() -> void:
        add_autoload_singleton("Finder", "res://addons/finder/finder.gd")


func _exit_tree() -> void:
        remove_autoload_singleton("Finder")