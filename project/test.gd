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


func _process(_delta: float) -> void:
	pass
