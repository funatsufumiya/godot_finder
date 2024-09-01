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

	assert(sprites.size() == 4)
	
	var my_sprites = Finder.find_children_by_type(root, "MySprite")
	print(my_sprites)

	assert(my_sprites.size() == 2)

	var my_sprite1 = my_sprites[0] as MySprite
	my_sprite1.hello()

	var my_parent = Finder.find_parent_by_name(test1, "SampleScene")
	print(my_parent)

	assert(my_parent == root)

	var my_parent2 = Finder.find_parent_by_type(test1, "Node2D")
	print(my_parent2)

	assert(my_parent2 == root)

	var test_sprite4 = Finder.find_child_by_name(root, "TestSprite4")
	print(test_sprite4)

	var some_parent = Finder.find_child_by_name(root, "SomeParent")
	var other_parent = Finder.find_child_by_name(root, "OtherParent")

	var test_sprite4_parent = Finder.find_parent_by_type(test_sprite4, "Node2D")
	print(test_sprite4_parent)

	assert(test_sprite4_parent == other_parent)

	var test_sprite4_parents = Finder.find_parents_by_type(test_sprite4, "Node2D")
	print(test_sprite4_parents)

	assert(test_sprite4_parents.size() == 3)
	assert(test_sprite4_parents[0] == other_parent)
	assert(test_sprite4_parents[1] == some_parent)
	assert(test_sprite4_parents[2] == root)


func _process(_delta: float) -> void:
	pass
