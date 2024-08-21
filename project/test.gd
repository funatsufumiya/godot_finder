extends Node

func _ready() -> void:
	# var singleton = Finder.get_singleton()
	# print(singleton.get_root())

	var root = Finder.get_root()
	print(root)

	var test1 = Finder.find_child_by_name(root, "Test1")
	print(test1)

	var test_sprite1 = Finder.find_child_by_type(root, "Sprite2D")
	print(test_sprite1)

	var sprites = Finder.find_children_by_type(root, "Sprite2D")
	print(sprites)


func _process(delta: float) -> void:
	pass
