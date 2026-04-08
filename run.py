from subprocess import run

run(["cmake", ".", "-B", "build"])
run(["cmake", "--build", "build"])
run(["./build/Source/Main/CoreTypes"])