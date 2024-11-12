#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct Heaplizer {
	//type Type = NULL;
	typedef void* Type;
	//type T = Type;

	void* Memory = NULL;
	Type* Value = NULL;
};

template<class T>
Heaplizer ConstructHeaplizer<T>(T& In) {
	Heaplizer H;
	H.Memory = calloc(1, size_t(T));
	H.Value = (T*)H.Memory;

	return H;
}
bool Free(Heaplizer& In) {
	free(In.Memory);
	In.Memory = NULL;
	In.Value = NULL;

	return true;
}
bool ShalowCopy(Heaplizer& In, In::T& B) {
	(*In.Value) = B;
	return true;
}
In::T* GetT(Heaplizer& In) {
	return In.Value;
}