class_name MySprite
extends Sprite2D


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	pass

func hello() -> void:
	print("Hello from MySprite (name: " + str(get_name()) + ")")
