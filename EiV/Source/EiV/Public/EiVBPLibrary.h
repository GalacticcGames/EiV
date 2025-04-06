// Copyright 2025, Galacticc Games. All rights reserved.

/* Licensed under MIT license. See LICENSE for full license text.
*
*        Created: 20th March 2025
*  Last Modified: 6th April 2025
*/

#pragma once

//<><><><><><><><><><><><> EiVLibrary Import Block <><><><><><><><><><><><>
//imports the specified headers by the macro definitions

#define EIV_INCLUDE_DENSE_MATRIX_ARRAY    //includes most core and basic features
#define EIV_INCLUDE_DENSE_LINEAR_PROBLEMS //includes solvers
#define EIV_INCLUDE_SPARSE_LINEAR_ALGEBRA //includes sparse linear algebra utilities
#define EIV_INCLUDE_GEOMETRY              //includes geometric utilities
#define EIV_UNDEFINE_INCLUDES             //ensures that these include macros above are local to this file

#include "EiVLibrary.h"   //takes the EIV_INCLUDE macros as settings and retrieves 
                          //the specified Eigen modules, typedefs, and helper functions
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EiVBPLibrary.generated.h"

//;:;:;:;:;:;:;:;:;:;:;:;: Define Encapsulatory structs ;:;:;:;:;:;:;:;:;:;:;:;:

USTRUCT(BlueprintType)
struct FEiVQuaternion
{
	GENERATED_BODY()
public:
	EiVQuaterniond Quat;
	FEiVQuaternion() {
		Quat = FEiVHelper::QuatToQuaternion(FQuat(0, 0, 0, 0));
	}
	FEiVQuaternion(FQuat Quaternion) {
		Quat = FEiVHelper::QuatToQuaternion(Quaternion);
	}
};

USTRUCT(BlueprintType)
struct FEiVUniformScaling
{
	GENERATED_BODY()
public:
	EiVUniformScaling<double> Scaling;
	FEiVUniformScaling() {
		Scaling = FEiVHelper::ScalarToUniformScaling(0.0);
	}
	FEiVUniformScaling(double Scalar) {
		Scaling = FEiVHelper::ScalarToUniformScaling(Scalar);
	}
};

USTRUCT(BlueprintType)
struct FEiVRotation2D
{
	GENERATED_BODY()
public:
	EiVRotation2Dd Rotation;
	FEiVRotation2D() {
		Rotation = FEiVHelper::RotatorTo2DRotation(FRotator(0,0,0));
	}
	FEiVRotation2D(FRotator Rotator) {
		Rotation = FEiVHelper::RotatorTo2DRotation(Rotator);
	}
};

USTRUCT(BlueprintType)
struct FEiVAngleAxis
{
	GENERATED_BODY()
public:
	EiVAngleAxisd AngleAxis;
	FEiVAngleAxis() {
		AngleAxis = FEiVHelper::QuatToAngleAxis(FQuat(0, 0, 0, 0));
	}
	FEiVAngleAxis(FQuat Quaternion) {
		AngleAxis = FEiVHelper::QuatToAngleAxis(Quaternion);
	}
	FEiVAngleAxis(FRotator Rotator) {
		AngleAxis = FEiVHelper::RotatorToAngleAxis(Rotator);
	}
};

USTRUCT(BlueprintType)
struct FEiVTranslation
{
	GENERATED_BODY()
public:
	EiVTranslation3d Translation;
	FEiVTranslation() {
		Translation = FEiVHelper::VectorToTranslation(FVector(0, 0, 0));
	}
	FEiVTranslation(FVector2D InVector) {
		Translation = FEiVHelper::VectorToTranslation(FVector(InVector.X, InVector.Y, 0));
	}
	FEiVTranslation(FVector InVector) {
		Translation = FEiVHelper::VectorToTranslation(InVector);
	}
};

USTRUCT(BlueprintType)
struct FEiVAxisAlignedBox
{
	GENERATED_BODY()
public:
	EiVAlignedBox3d AABox;
	FEiVAxisAlignedBox() {
		AABox = FEiVHelper::FBoxToAABox(FBox(FVector().ZeroVector, FVector().ZeroVector));
	}
	FEiVAxisAlignedBox(FBox2D InBox) {
		AABox = FEiVHelper::FBoxToAABox(FBox(FVector(InBox.Min.X,InBox.Min.Y,0), FVector(InBox.Max.X, InBox.Max.Y,0)));
	}
	FEiVAxisAlignedBox(FBox InBox) {
		AABox = FEiVHelper::FBoxToAABox(InBox);
	}
};

USTRUCT(BlueprintType)
struct FEiVParameterizedLine
{
	GENERATED_BODY()
public:
	EiVParameterizedLine<double,3> Line;
	FEiVParameterizedLine() {
		Line = FEiVHelper::VectorToParameterizedLine(FVector(0,0,0));
	}
	FEiVParameterizedLine(FVector2D InVector) {
		Line = FEiVHelper::VectorToParameterizedLine(FVector(InVector.X, InVector.Y, 0));
	}
	FEiVParameterizedLine(FVector InVector) {
		Line = FEiVHelper::VectorToParameterizedLine(InVector);
	}
	FEiVParameterizedLine(FRay InRay) {
		Line = FEiVHelper::RayToParameterizedLine(InRay);
	}
};

USTRUCT(BlueprintType)
struct FEiVComplexNumber
{
	GENERATED_BODY()
public:
	std::complex<double> Complex;
	FEiVComplexNumber() {
		Complex = FEiVHelper::Vector2DToComplex(FVector2D(0, 0),false);
	}
	FEiVComplexNumber(FVector2D InVector, bool AsPhasor) {
		Complex = FEiVHelper::Vector2DToComplex(InVector, AsPhasor);
	}
	FEiVComplexNumber(std::complex<double> C) {
		Complex = C;
	}
};

USTRUCT(BlueprintType)
struct FEiVArray
{
	GENERATED_BODY()
public:
	EiVArrayX<double> Array;
	FEiVArray() {
		Array = FEiVHelper::TArrayToDynamicArray({});
	}
	FEiVArray(TArray<double> InArray) {
		Array = FEiVHelper::TArrayToDynamicArray(InArray);
	}
};

USTRUCT(BlueprintType)
struct FEiVTriplet
{
	GENERATED_BODY()
public:
	EiVTriplet<double> Triplet;
	FEiVTriplet() {
		Triplet = FEiVHelper::VectorToTriplet(FVector(0, 0, 0));
	}
	FEiVTriplet(FVector Vector) {
		Triplet = FEiVHelper::VectorToTriplet(Vector);
	}
};

USTRUCT(BlueprintType)
struct FEiVJacobiRotation
{
	GENERATED_BODY()
public:
	EiVJacobiRotation<double> Rotation;
	FEiVJacobiRotation() {
		Rotation = FEiVHelper::Vector2DToJacobiRotation(FVector2D(0, 0));
	}
	FEiVJacobiRotation(FVector2D Vector) {
		Rotation = FEiVHelper::Vector2DToJacobiRotation(Vector);
	}
};

USTRUCT(BlueprintType)
struct FEiVVector
{
	GENERATED_BODY()
public:
	EiVVector4d Vector;
	FEiVVector() {
		Vector = FEiVHelper::FVectorToVector(FVector4(0, 0, 0, 0));
	}
	FEiVVector(FVector2D InVector) {
		Vector = FEiVHelper::FVectorToVector(FVector4(InVector.X, InVector.Y, 0, 0));
	}
	FEiVVector(FVector InVector) {
		Vector = FEiVHelper::FVectorToVector(FVector4(InVector.X, InVector.Y, InVector.Z, 0));
	}
	FEiVVector(FVector4 InVector) {
		Vector = FEiVHelper::FVectorToVector(InVector);
	}
};

USTRUCT(BlueprintType)
struct FEiVRowVector
{
	GENERATED_BODY()
public:
	EiVRowVector4d Vector;
	FEiVRowVector() {
		Vector = FEiVHelper::FVectorToRowVector(FVector4(0, 0, 0, 0));
	}
	FEiVRowVector(FVector2D InVector) {
		Vector = FEiVHelper::FVectorToRowVector(FVector4(InVector.X, InVector.Y, 0, 0));
	}
	FEiVRowVector(FVector InVector) {
		Vector = FEiVHelper::FVectorToRowVector(FVector4(InVector.X, InVector.Y, InVector.Z, 0));
	}
	FEiVRowVector(FVector4 InVector) {
		Vector = FEiVHelper::FVectorToRowVector(InVector);
	}
};

USTRUCT(BlueprintType)
struct FEiVSparseVector
{
	GENERATED_BODY()
public:
	EiVSparseVector<double> Vector;
	FEiVSparseVector() {
		Vector = FEiVHelper::VectorToSparseVector(FVector4(0, 0, 0, 0));
	}
	FEiVSparseVector(FVector2D InVector) {
		Vector = FEiVHelper::VectorToSparseVector(FVector4(InVector.X, InVector.Y, 0, 0));
	}
	FEiVSparseVector(FVector InVector) {
		Vector = FEiVHelper::VectorToSparseVector(FVector4(InVector.X, InVector.Y, InVector.Z, 0));
	}
	FEiVSparseVector(FVector4 InVector) {
		Vector = FEiVHelper::VectorToSparseVector(InVector);
	}
};

USTRUCT(BlueprintType)
struct FEiVNullMatrix
{
	GENERATED_BODY()
public:
	EiVMatrix<double, 0, 0> Matrix;
	FEiVNullMatrix() {
		Matrix = FEiVHelper::NullMatrix();
	}
};

USTRUCT(BlueprintType)
struct FEiVMatrix
{
	GENERATED_BODY()
public:
	EiVMatrix4d Matrix{ {0,0,0,0},{0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
	FEiVMatrix() {

	}
	FEiVMatrix(FMatrix InMatrix) {
		Matrix = FEiVHelper::FMatrixToMatrix(InMatrix);
	}
};

USTRUCT(BlueprintType)
struct FEiVSparseMatrix
{
	GENERATED_BODY()
public:
	EiVSparseMatrix<double> Matrix;
	FEiVSparseMatrix() {
		Matrix = EiVSparseMatrix<double>();
	}
	FEiVSparseMatrix(FMatrix InMatrix) {
		Matrix = FEiVHelper::FMatrixToSparseMatrix(InMatrix);
	}
	FEiVSparseMatrix(TArray<double> InMatrix, int32 Rows, int32 Cols) {
		Matrix = FEiVHelper::TArrayToSparseMatrix(InMatrix, Rows, Cols);
	}
};

USTRUCT(BlueprintType)
struct FEiVDynamicMatrix
{
	GENERATED_BODY()
public:
	EiVMatrixXd Matrix;
	FEiVDynamicMatrix() {
		Matrix = EiVMatrixXd();
	}
	FEiVDynamicMatrix(EiVVectorXd Vector,bool Vec) {
		Matrix = Vector;
	}
	FEiVDynamicMatrix(EiVMatrixXd InMatrix) {
		Matrix = InMatrix;
	}
	FEiVDynamicMatrix(TArray<double> InMatrix, int32 Rows, int32 Cols) {
		EiVMatrixXd Mtx(Rows, Cols);
		for (int row = 0; row < Rows; row++) {
			for (int col = 0; col < Cols && (col + row * Cols) < InMatrix.Num(); col++) {
				Mtx.coeffRef(row, col) = InMatrix[col + row * Cols];
			}
		}
		Matrix = Mtx;
	}
};

USTRUCT(BlueprintType)
struct FEiVDynamicComplexMatrix
{
	GENERATED_BODY()
public:
	EiVMatrixXcd Matrix;
	FEiVDynamicComplexMatrix() {
		Matrix = EiVMatrixXcd();
	}
	FEiVDynamicComplexMatrix(EiVVectorXcd Vector,bool Vec) {
		Matrix = Vector;
	}
	FEiVDynamicComplexMatrix(EiVMatrixXcd Vector) {
		Matrix = Vector;
	}
	FEiVDynamicComplexMatrix(TArray<FEiVComplexNumber> InMatrix, int32 Rows, int32 Cols) {
		EiVMatrixXcd Mtx(Rows, Cols);
		for (int row = 0; row < Rows; row++) {
			for (int col = 0; col < Cols && (col + row * Cols) < InMatrix.Num(); col++) {
				Mtx.coeffRef(row, col) = InMatrix[col + row * Cols].Complex;
			}
		}
		Matrix = Mtx;
	}
};

USTRUCT(BlueprintType)
struct FEiVDynamicVector
{
	GENERATED_BODY()
public:
	EiVVectorXd Vector;
	FEiVDynamicVector() {
		Vector = EiVMatrixXd();
	}
	FEiVDynamicVector(int32 Rows) {
		Vector = EiVVectorXd::Random(Rows);
	}
	FEiVDynamicVector(TArray<double> InVector, int32 Rows) {
		EiVVectorXd Vec(Rows);
		for (int row = 0; row < Rows && row < InVector.Num(); row++) {
			Vec.coeffRef(row) = InVector[row];
		}
		Vector = Vec;
	}
};

UENUM()
enum class EEiVBPFuncSuccess : uint8
{
	SUCCESS,
	FAILURE
};

//;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:

UCLASS()
class UEiVBPLibrary : public UBlueprintFunctionLibrary 
{
	GENERATED_UCLASS_BODY()

//=========================================================================================//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Eigen Blueprint Analogs ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//=========================================================================================//

	//Adds two matrices. They must be the same size (rows and columns) or the null matrix is returned.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Add Matrices", CompactNodeTitle = "A+B", Keywords = "EiV Eigen Matrix Add", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Matrix")
	static void EiVAddMatrix(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& Matrix);
	//Subtracts two matrices. They must be the same size (rows and columns) or the null matrix is returned.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Subtract Matrices", CompactNodeTitle = "A-B", Keywords = "EiV Eigen Matrix Subtract Minus", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Matrix")
	static void EiVSubtractMatrix(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& Matrix);
	//Multiplies a matrix by a scalar. 
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Scalar Multiply Matrix", CompactNodeTitle = "s*A", Keywords = "EiV Eigen Matrix Multiply times scalar", AutoCreateRefTerm = "s, A"), Category = "EiV|Core|Matrix")
	static void EiVScalarMultiplyMatrix(double s, FEiVDynamicMatrix A, FEiVDynamicMatrix& Matrix);
	//Divides a matrix by a scalar. If the scalar is zero, the null matrix is returned.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Scalar Divide Matrix", CompactNodeTitle = "A/s", Keywords = "EiV Eigen Matrix Divide scalar", AutoCreateRefTerm = "A, s"), Category = "EiV|Core|Matrix")
	static void EiVScalarDivideMatrix(FEiVDynamicMatrix A, double s, FEiVDynamicMatrix& Matrix);
	//Transposes a matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Transpose Matrix", CompactNodeTitle = "A^T", Keywords = "EiV Eigen Matrix Transpose", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVTransposeMatrix(FEiVDynamicMatrix A, FEiVDynamicMatrix& Matrix);
	//Gets the conjugate of a matrix
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Conjugate Matrix", CompactNodeTitle = "conjugate", Keywords = "EiV Eigen Matrix Conjugate", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVConjugateMatrix(FEiVDynamicComplexMatrix A, FEiVDynamicComplexMatrix& Matrix);
	//Gets the adjoint of a matrix
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Adjoint Matrix", CompactNodeTitle = "A*", Keywords = "EiV Eigen Matrix Adjoint", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVAdjointMatrix(FEiVDynamicMatrix A, FEiVDynamicMatrix& Matrix);
	//Multiply two matrices together. The columns of A must be the same size as the rows of B otherwise the null matrix is returned.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Multiplication", CompactNodeTitle = "A*B", Keywords = "EiV Eigen Matrix Multiply times", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Matrix")
	static void EiVMatrixMultiplication(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& Matrix);
	//Calculate the dot product of two vectors. Both of these matrices must be the same size. Only their first column is used for this operation. It is often best to use matrices from dynamic vectors for this.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Dot Product", CompactNodeTitle = "A dot B", Keywords = "EiV Eigen Matrix dot product vector", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Vector")
	static void EiVDotProduct(FEiVDynamicMatrix A, FEiVDynamicMatrix B, double& DotProduct);
	//Calculate the cross product of two vectors. Both of these matrices must be the 3x3. Only thier first column is used for this operation. It is often best to use matrices from dynamic vectors for this. If any of these conditions are violated the null matrix is returned.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Cross Product", CompactNodeTitle = "A cross B", Keywords = "EiV Eigen Matrix cross product vector", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Vector")
	static void EiVCrossProduct(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& CrossProduct);
	//The number of rows in a matrix
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Rows", CompactNodeTitle = "rows", Keywords = "EiV Eigen Matrix rows", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixRows(FEiVDynamicMatrix A, int& Rows);
	//The number of columns in a matrix
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Columns", CompactNodeTitle = "columns", Keywords = "EiV Eigen Matrix columns", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixColumns(FEiVDynamicMatrix A, int& Columns);
	//The number of entries in a matrix
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Size", CompactNodeTitle = "size", Keywords = "EiV Eigen Matrix size", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixSize(FEiVDynamicMatrix A, int& Size);
	//Sum the elements of a matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Sum", CompactNodeTitle = "sum A", Keywords = "EiV Eigen Matrix sum", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixSum(FEiVDynamicMatrix A, double& Sum);
	//Multiply the elements of a matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Product", CompactNodeTitle = "prod A", Keywords = "EiV Eigen Matrix product", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixProduct(FEiVDynamicMatrix A, double& Product);
	//Average the elements of a matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Mean", CompactNodeTitle = "avg A", Keywords = "EiV Eigen Matrix mean average", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixMean(FEiVDynamicMatrix A, double& Mean);
	//Trace the elements of a matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Trace", CompactNodeTitle = "Tr(A)", Keywords = "EiV Eigen Matrix trace diagonal", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixTrace(FEiVDynamicMatrix A, double& Trace);
	//Get the smallest element in a matrix
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Min", Keywords = "EiV Eigen Matrix minimum coefficient", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixMin(FEiVDynamicMatrix A, double& Minimum, int& Row, int& Column);
	//Get the largest element in a matrix
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Max", Keywords = "EiV Eigen Matrix maximum coefficient", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixMax(FEiVDynamicMatrix A, double& Maximum, int& Row, int& Column);
	//Gets a block of a matrix. The block size must be within the matrix or the null matrix is returned
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Block", Keywords = "EiV Eigen Matrix Block", AutoCreateRefTerm = "A, StartRow, StartCol, BlockWidth, BlockHeight"), Category = "EiV|Core|Matrix")
	static void EiVMatrixBlock(FEiVDynamicMatrix A, int32 StartRow, int32 StartCol, int32 BlockWidth, int32 BlockHeight, FEiVDynamicMatrix& Block);
	//Gets a row of a matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Row", Keywords = "EiV Eigen Matrix Row", AutoCreateRefTerm = "A, RowIndex"), Category = "EiV|Core|Matrix")
	static void EiVMatrixRow(FEiVDynamicMatrix A, int32 RowIndex, FEiVDynamicMatrix& Row);
	//Gets a column of a matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Column", Keywords = "EiV Eigen Matrix Column", AutoCreateRefTerm = "A, ColIndex"), Category = "EiV|Core|Matrix")
	static void EiVMatrixColumn(FEiVDynamicMatrix A, int32 ColIndex, FEiVDynamicMatrix& Column);
	//Gets an element of a matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Get Element", Keywords = "EiV Eigen Matrix Get Element", AutoCreateRefTerm = "A, RowIndex, ColIndex"), Category = "EiV|Core|Matrix")
	static void EiVGetMatrixElement(FEiVDynamicMatrix A, int32 RowIndex, int32 ColIndex, double& Element);
	//Sets an element of a matrix.
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Matrix Set Element", Keywords = "EiV Eigen Matrix Set Element", AutoCreateRefTerm = "A, RowIndex, ColIndex"), Category = "EiV|Core|Matrix")
	static void EiVSetMatrixElement(FEiVDynamicMatrix A, int32 RowIndex, int32 ColIndex, double Element, FEiVDynamicMatrix& Matrix);
	//Reshapes a matrix to a given size
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Reshape", Keywords = "EiV Eigen Matrix Reshape", AutoCreateRefTerm = "A, RowIndex, ColIndex"), Category = "EiV|Core|Matrix")
	static void EiVMatrixReshape(FEiVDynamicMatrix A, int32 RowSize, int32 ColSize, FEiVDynamicMatrix& Reshaped);
	//Solves a basic linear system. B must be a vector of the same length as the number of rows of A.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Solve (ColPivHHQR)", CompactNodeTitle = "Ax=B", Keywords = "EiV Eigen Matrix Solve", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Matrix")
	static void EiVColPivHHQR(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& Solution);
	//Computes the Eigenvalues of the matrix. It is not successful if the Eigenvector/Eigenvalue decomposition diverges (this is only on rare occasions).
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Matrix Eigenvalues", Keywords = "EiV Eigen Matrix Eigenvalues", AutoCreateRefTerm = "A", ExpandEnumAsExecs = "Success"), Category = "EiV|Core|Matrix")
	static void EiVMatrixEigenvalues(FEiVDynamicMatrix A, EEiVBPFuncSuccess& Success, FEiVDynamicComplexMatrix& Solution);
	//Computes the Eigenvectors of the matrix. It is not successful if the Eigenvector/Eigenvalue decomposition diverges (this is only on rare occasions).
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Matrix Eigenvectors", Keywords = "EiV Eigen Matrix Eigenvectors", AutoCreateRefTerm = "A", ExpandEnumAsExecs = "Success"), Category = "EiV|Core|Matrix")
	static void EiVMatrixEigenvectors(FEiVDynamicMatrix A, EEiVBPFuncSuccess& Success, FEiVDynamicComplexMatrix& Solution);
	//Gets the determinant of the matrix
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Determinant", CompactNodeTitle = "det A", Keywords = "EiV Eigen Matrix Determinant", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixDeterminant(FEiVDynamicMatrix A, double& Determinant);
	//Gets the inverse of the matrix if it exists. If it does not exist, the null matrix is returned.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Inverse", CompactNodeTitle = "A^(-1)", Keywords = "EiV Eigen Matrix Inverse", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixInverse(FEiVDynamicMatrix A, FEiVDynamicMatrix& Inverse);
	//Gets the rank of the matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix Rank", CompactNodeTitle = "rank", Keywords = "EiV Eigen Matrix Rank", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixRank(FEiVDynamicMatrix A, int& Rank);
	//Gets a string representation of the matrix.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Matrix To String", Keywords = "EiV Eigen Matrix String", AutoCreateRefTerm = "A"), Category = "EiV|Core|Matrix")
	static void EiVMatrixToString(FEiVDynamicMatrix A, FString& String);
	//Get Eigen array element
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Get", Keywords = "EiV Eigen Array get element", AutoCreateRefTerm = "A"), Category = "EiV|Core|Array")
	static void EiVArrayGetElement(FEiVArray A, int Index, double& Element);
	//Set Eigen array element
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Array Set", Keywords = "EiV Eigen Array set element", AutoCreateRefTerm = "A"), Category = "EiV|Core|Array")
	static void EiVArraySetElement(UPARAM(ref) FEiVArray& A, int Index, double Element);
	//Add Eigen arrays
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Add", CompactNodeTitle = "[A] + [B]", Keywords = "EiV Eigen Array add", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Array")
	static void EiVArrayAdd(FEiVArray A, FEiVArray B, FEiVArray& Array);
	//Subtract Eigen arrays
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Subtract", CompactNodeTitle = "[A] - [B]", Keywords = "EiV Eigen Array subtract minus", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Array")
	static void EiVArraySubtract(FEiVArray A, FEiVArray B, FEiVArray& Array);
	//Scalar multiply Eigen arrays
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Scalar Multiply", CompactNodeTitle = "s*[A]", Keywords = "EiV Eigen Array scalar multiply", AutoCreateRefTerm = "S, A"), Category = "EiV|Core|Array")
	static void EiVArrayScalarMultiply(double s, FEiVArray A, FEiVArray& Array);
	//Add scalars to Eigen arrays
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Scalar Add", CompactNodeTitle = "[A] + s", Keywords = "EiV Eigen Array scalar add", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Array")
	static void EiVArrayScalarAdd(FEiVArray A, double s, FEiVArray& Array);
	//Subtract scalars from Eigen arrays
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Scalar Subtract", CompactNodeTitle = "[A] - s", Keywords = "EiV Eigen Array scalar subtract minus", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Array")
	static void EiVArrayScalarSubtract(FEiVArray A, double s, FEiVArray& Array);
	//Multiplies Eigen arrays in a component-wsie manner
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Multiply", CompactNodeTitle = "[A] * [B]", Keywords = "EiV Eigen Array multiply times", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Array")
	static void EiVArrayMultiply(FEiVArray A, FEiVArray B, FEiVArray& Array);
	//Creates an Eigen array of the minimum values of the input arrays (inputs must b the same length).
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Min", CompactNodeTitle = "min [A],[B]", Keywords = "EiV Eigen Array minimum", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Array")
	static void EiVArrayMin(FEiVArray A, FEiVArray B, FEiVArray& Array);
	//Creates an Eigen array of the maximum values of the input arrays (inputs must b the same length).
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Max", CompactNodeTitle = "max [A],[B]", Keywords = "EiV Eigen Array maximum", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Array")
	static void EiVArrayMax(FEiVArray A, FEiVArray B, FEiVArray& Array);
	//Creates an Eigen array of the absolute values of the input array.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array Absolute Value", CompactNodeTitle = "|[A]|", Keywords = "EiV Eigen Array maximum", AutoCreateRefTerm = "A, B"), Category = "EiV|Core|Array")
	static void EiVArrayAbs(FEiVArray A, FEiVArray& Array);
	//Creates a string of the array
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Array To String", Keywords = "EiV Eigen Array string", AutoCreateRefTerm = "A"), Category = "EiV|Core|Array")
	static void EiVArrayToString(FEiVArray A, FString& String);

//=========================================================================================//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FEiVHelper Blueprint functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//=========================================================================================//

	//Creates a dynamic complex-valued Eigen matrix that can be of any size. It should be expected that the array elements are inserted and accessed in Row-Major Order.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create Dynamic Complex Matrix", Keywords = "EiV Eigen Dynamic Complex Matrix", AutoCreateRefTerm = "Array, Rows, Cols"), Category = "EiV|Core|Matrix")
	static void EiVMakeDynamicComplexMatrix(TArray<FEiVComplexNumber> Array, int32 Rows, int32 Cols, FEiVDynamicComplexMatrix& Matrix);
	//Creates an array from the context of a dynamic complex matrix in Row-Major Order
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Dynamic Complex Matrix To Array", Keywords = "EiV Eigen Dynamic Complex Matrix Array", AutoCreateRefTerm = "Matrix"), Category = "EiV|Core|Matrix")
	static void EiVDynamicComplexMatrixToArray(FEiVDynamicComplexMatrix Matrix, TArray<FEiVComplexNumber>& Array);
	//Creates a dynamic matrix containing just the imaginary components
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Strip Real", Keywords = "EiV Eigen Dynamic Complex Matrix Strip Real", AutoCreateRefTerm = "Matrix"), Category = "EiV|Core|Matrix")
	static void EiVStripReals(FEiVDynamicComplexMatrix Matrix, FEiVDynamicMatrix& ImaginaryMatrix);
	//Creates a dynamic matrix containing just the real components
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Strip Imaginary", Keywords = "EiV Eigen Dynamic Complex Matrix Strip Imaginary", AutoCreateRefTerm = "Matrix"), Category = "EiV|Core|Matrix")
	static void EiVStripImaginary(FEiVDynamicComplexMatrix Matrix, FEiVDynamicMatrix& RealMatrix);
	//Creates an array from the context of a dynamic matrix in Row-Major Order
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Dynamic Matrix To Array", Keywords = "EiV Eigen Dynamic Matrix Array", AutoCreateRefTerm = "Matrix"), Category = "EiV|Core|Matrix")
	static void EiVDynamicMatrixToArray(FEiVDynamicMatrix Matrix, TArray<double>& Array);
	//Creates a dynamic Eigen matrix that can be of any size. It should be expected that the array elements are inserted and accessed in Row-Major Order.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create Dynamic Matrix", Keywords = "EiV Eigen Dynamic Matrix", AutoCreateRefTerm = "Array, Rows, Cols"), Category = "EiV|Core|Matrix")
	static void EiVMakeDynamicMatrix(TArray<double> Array, int32 Rows, int32 Cols, FEiVDynamicMatrix& Matrix);
	//Creates a dynamic Eigen vector that can be of any size.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create Dynamic Vector", Keywords = "EiV Eigen Dynamic Vector", AutoCreateRefTerm = "Array, Rows"), Category = "EiV|Core|Vector")
	static void EiVMakeDynamicVector(TArray<double> Array, int32 Rows, FEiVDynamicMatrix& Vector);
	//Creates a dynamic Eigen matrix that can be of any size with random elements from 0 to 1.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create Random Dynamic Matrix", Keywords = "EiV Eigen Dynamic Matrix Random", AutoCreateRefTerm = "Array, Rows, Cols"), Category = "EiV|Core|Matrix")
	static void EiVMakeRandomDynamicMatrix(int32 Rows, int32 Cols, FEiVDynamicMatrix& Matrix);
	//Creates a dynamic Eigen vector that can be of any size with random elements from 0 to 1.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create Random Dynamic Vector", Keywords = "EiV Eigen Dynamic Vector Random", AutoCreateRefTerm = "Rows"), Category = "EiV|Core|Vector")
	static void EiVMakeRandomDynamicVector(int32 Rows, FEiVDynamicMatrix& Vector);
	//This sets the number of threads Eigen can use at any given time
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Eigen Threads", Keywords = "EiV Eigen Threads"), Category = "EiV")
	static void EiVSetEigenThreads(int32 Threads);
	//This gets the number of threads Eigen can use at any given time
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Eigen Threads", Keywords = "EiV Eigen Threads"), Category = "EiV")
	static void EiVGetEigenThreads(int32& Threads);
	//This converts Vector2Ds into complex numbers (x is real and y is imaginary). As Phasor makes the input/output represent a complex number as an angle and distance from the rea axis.
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector2D To Complex", Keywords = "EiV Eigen Vector2D Complex", AutoCreateRefTerm = "Vector, AsPhasor, ComplexNumber"), Category = "EiV")
	static void EiVVector2DToComplex(FVector2D Vector, bool AsPhasor, FEiVComplexNumber ComplexNumber, FVector2D& OutVector, FEiVComplexNumber& OutComplexNumber);
	//This gets the null matrix (a matrix of size 0)
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Null Matrix", Keywords = "EiV Eigen Null Matrix"), Category = "EiV|Core|Matrix")
	static void EiVNullMatrix(FEiVNullMatrix& NullMatrix);
	//This makes the null matrix into a dynamic matrix
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Null Matrix To Dynamic Matrix", Keywords = "EiV Eigen Null Matrix Dynamic"), Category = "EiV|Core|Matrix") 
	static void EiVNullMatrixAsDynamic(FEiVNullMatrix NullMatrix, FEiVDynamicMatrix& Matrix);
	//Converts between Unreal Engine and Eigen Array types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Array To Eigen Array", Keywords = "EiV Eigen Array", AutoCreateRefTerm = "Array, EigenArray"), Category = "EiV|Core|Array")
	static void EiVArrayToEigenArray(TArray<double> Array, FEiVArray EigenArray, TArray<double>& OutArray, FEiVArray& OutEigenArray);
	//Converts between Unreal Engine and Eigen Vector types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector2D To Eigen-Type Vector", Keywords = "EiV Eigen Vector2D", AutoCreateRefTerm = "Vector, EiVVector"), Category = "EiV|Core|Vector")
	static void EiVVector2DToEiVVector(FVector2D Vector, FEiVVector EiVVector, FVector2D& OutVector, FEiVVector& OutEiVVector);
	//Converts between Unreal Engine and Eigen Vector types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector To Eigen-Type Vector", Keywords = "EiV Eigen Vector", AutoCreateRefTerm = "Vector, EiVVector"), Category = "EiV|Core|Vector")
	static void EiVVectorToEiVVector(FVector Vector, FEiVVector EiVVector, FVector& OutVector, FEiVVector& OutEiVVector);
	//Creates a dynamic vector from this vector
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector To Dynamic Vector", Keywords = "EiV Eigen Dynamic Vector", AutoCreateRefTerm = "Vector"), Category = "EiV|Core|Vector")
	static void EiVVectorToDynamicVector(FEiVVector Vector, FEiVDynamicMatrix& OutDynamicVector);
	//Converts between Unreal Engine and Eigen Vector types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector4 To Eigen-Type Vector", Keywords = "EiV Eigen Vector4", AutoCreateRefTerm = "Vector, EiVVector"), Category = "EiV|Core|Vector")
	static void EiVVector4ToEiVVector(FVector4 Vector, FEiVVector EiVVector, FVector4& OutVector, FEiVVector& OutEiVVector);
	//Converts between Unreal Engine Vectors and Eigen Row Vector types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector2D To Row Vector", Keywords = "EiV Eigen Row Vector2D", AutoCreateRefTerm = "Vector, RowVector"), Category = "EiV|Core|Row Vector")
	static void EiVVector2DToRowVector(FVector2D Vector, FEiVRowVector RowVector, FVector2D& OutVector, FEiVRowVector& OutRowVector);
	//Converts between Unreal Engine Vectors and Eigen Row Vector types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector To Row Vector", Keywords = "EiV Eigen  Row Vector", AutoCreateRefTerm = "Vector, RowVector"), Category = "EiV|Core|Row Vector")
	static void EiVVectorToRowVector(FVector Vector, FEiVRowVector RowVector, FVector& OutVector, FEiVRowVector& OutRowVector);
	//Creates a dynamic vector from this row vector
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Row Vector To Dynamic Vector", Keywords = "EiV Eigen Dynamic Row Vector", AutoCreateRefTerm = "Vector"), Category = "EiV|Core|Row Vector")
	static void EiVRowVectorToDynamicVector(FEiVRowVector Vector, FEiVDynamicMatrix& OutDynamicVector);
	//Converts between Unreal Engine Vectors and Eigen Row Vector types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector4 To Row Vector", Keywords = "EiV Eigen Row Vector4", AutoCreateRefTerm = "Vector, RowVector"), Category = "EiV|Core|Row Vector")
	static void EiVVector4ToRowVector(FVector4 Vector, FEiVRowVector RowVector, FVector4& OutVector, FEiVRowVector& OutRowVector);
	//Converts between Unreal Engine Matrices and Eigen Matrix types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Matrix To Eigen Matrix", Keywords = "EiV Eigen Matrix", AutoCreateRefTerm = "Matrix, EigenMatrix"), Category = "EiV|Core|Matrix")
	static void EiVMatrixToEigenMatrix(FMatrix Matrix, FEiVMatrix EigenMatrix, FMatrix& OutMatrix, FEiVMatrix& OutEigenMatrix);
	//Creates a dynamic matrix from this Eigen matrix
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Eigen Matrix To Dynamic Matrix", Keywords = "EiV Eigen Dynamic Row Vector", AutoCreateRefTerm = "Matrix"), Category = "EiV|Core|Matrix")
	static void EiVEigenMatrixToDynamicMatrix(FEiVMatrix Matrix, FEiVDynamicMatrix& OutDynamicMatrix);
	//Converts between Unreal Engine Vector2Ds and Eigen JacobiRotation types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector2D To Jacobi Rotation", Keywords = "EiV Eigen Vector2D Jacobi Rotation", AutoCreateRefTerm = "Vector, JacobiRotation"), Category = "EiV|Jacobi|Jacobi Rotation")
	static void EiVVector2DToJacobiRotation(FVector2D Vector, FEiVJacobiRotation JacobiRotation, FVector2D& OutVector, FEiVJacobiRotation& OutJacobiRotation);
	//Converts between Unreal Engine Vectors and Eigen Triplet types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector To Triplet", Keywords = "EiV Eigen Vector Triplet", AutoCreateRefTerm = "Vector, Triplet"), Category = "EiV|Sparse Core|Triplet")
	static void EiVVectorToTriplet(FVector Vector, FEiVTriplet Triplet, FVector& OutVector, FEiVTriplet& OutTriplet);
	//Converts between Unreal Engine Vector and Eigen Sparse Vector types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector2D To Sparse Vector", Keywords = "EiV Eigen Vector2D Sparse", AutoCreateRefTerm = "Vector, SparseVector"), Category = "EiV|Sparse Core|Sparse Vector")
	static void EiVVector2DToSparseVector(FVector2D Vector, FEiVSparseVector SparseVector, FVector2D& OutVector, FEiVSparseVector& OutSparseVector);
	//Converts between Unreal Engine Vector and Eigen Sparse Vector types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector To Sparse Vector", Keywords = "EiV Eigen Vector Sparse", AutoCreateRefTerm = "Vector, SparseVector"), Category = "EiV|Sparse Core|Sparse Vector")
	static void EiVVectorToSparseVector(FVector Vector, FEiVSparseVector SparseVector, FVector& OutVector, FEiVSparseVector& OutSparseVector);
	//Converts between Unreal Engine Vector and Eigen Sparse Vector types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector4 To Sparse Vector", Keywords = "EiV Eigen Vector4 Sparse", AutoCreateRefTerm = "Vector, SparseVector"), Category = "EiV|Sparse Core|Sparse Vector")
	static void EiVVector4ToSparseVector(FVector4 Vector, FEiVSparseVector SparseVector, FVector4& OutVector, FEiVSparseVector& OutSparseVector);
	//Converts between Unreal Engine Matrices and Eigen Sparse Matrices (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Matrix To Sparse Matrix", Keywords = "EiV Eigen Sparse Matrix", AutoCreateRefTerm = "Matrix, SparseMatrix"), Category = "EiV|Sparse Core|Sparse Matrix")
	static void EiVMatrixToSparseMatrix(FMatrix Matrix, FEiVSparseMatrix SparseMatrix, FMatrix& OutMatrix, FEiVSparseMatrix& OutSparseMatrix);
	//Converts between Unreal Engine Arrays and Eigen Sparse Matrices (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Array To Sparse Matrix", Keywords = "EiV Eigen Sparse Matrix Array", AutoCreateRefTerm = "Array, Rows, Cols, SparseMatrix"), Category = "EiV|Sparse Core|Sparse Matrix")
	static void EiVArrayToSparseMatrix(TArray<double> Array, int32 Rows, int32 Cols, FEiVSparseMatrix SparseMatrix, TArray<double>& OutArray, FEiVSparseMatrix& OutSparseMatrix);
	//Converts between Unreal Engine and Eigen Quaternion types (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Quat To Quaternion", Keywords = "EiV Eigen Quat Quaternion", AutoCreateRefTerm = "Quat, Quaternion"), Category = "EiV|Geometry|Quaternion")
	static void EiVQuatToQuaternion(FQuat Quat, FEiVQuaternion Quaternion, FQuat& OutQuat, FEiVQuaternion& OutQuaternion);
	//Converts between an Unreal Engine Quaternion and an Eigen AngleAxis type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Quat To Angle Axis", Keywords = "EiV Eigen Quat Quaternion Angle Axis", AutoCreateRefTerm = "Quat, AngleAxis"), Category = "EiV|Geometry|AngleAxis")
	static void EiVQuatToAngleAxis(FQuat Quat, FEiVAngleAxis AngleAxis, FQuat& OutQuat, FEiVAngleAxis& OutAngleAxis);
	//Converts between an Unreal Engine Rotator and an Eigen AngleAxis type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Rotator To Angle Axis", Keywords = "EiV Eigen Rotator Rotation Angle Axis", AutoCreateRefTerm = "Rotator, AngleAxis"), Category = "EiV|Geometry|AngleAxis")
	static void EiVRotatorToAngleAxis(FRotator Rotator, FEiVAngleAxis AngleAxis, FRotator& OutRotator, FEiVAngleAxis& OutAngleAxis);
	//Converts between an Unreal Engine Rotator and an Eigen Rotation2D type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Rotator To Rotation 2D", Keywords = "EiV Eigen Rotator Rotation Rotation2D 2d", AutoCreateRefTerm = "Rotator, Rotation2D"), Category = "EiV|Geometry|Rotation2D")
	static void EiVRotatorToRotation2D(FRotator Rotator, FEiVRotation2D Rotation2D, FRotator& OutRotator, FEiVRotation2D& OutRotation2D);
	//Converts between an Unreal Engine Vector2D and an Eigen Translation type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector2D To Translation", Keywords = "EiV Eigen Vector Translation Vector2D 2d", AutoCreateRefTerm = "Vector, Translation"), Category = "EiV|Geometry|Translation")
	static void EiVVector2DToTranslation(FVector2D Vector, FEiVTranslation Translation, FVector2D& OutVector, FEiVTranslation& OutTranslation);
	//Converts between an Unreal Engine Vector and an Eigen Translation type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector To Translation", Keywords = "EiV Eigen Vector Translation", AutoCreateRefTerm = "Vector, Translation"), Category = "EiV|Geometry|Translation")
	static void EiVVectorToTranslation(FVector Vector, FEiVTranslation Translation, FVector& OutVector, FEiVTranslation& OutTranslation);
	//Converts between an Unreal Engine Box2D and an Eigen Axis-Aligned Box type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Box2D to Axis-Aligned Box", Keywords = "EiV Eigen Box Axis Aligned Box2D", AutoCreateRefTerm = "Box, AABox"), Category = "EiV|Geometry|Axis Aligned Box")
	static void EiVBox2DToAABox(FBox2D Box, FEiVAxisAlignedBox AABox, FBox2D& OutBox, FEiVAxisAlignedBox& OutAABox);
	//Converts between an Unreal Engine Box and an Eigen Axis-Aligned Box type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Box to Axis-Aligned Box", Keywords = "EiV Eigen Box Axis Aligned", AutoCreateRefTerm = "Box, AABox"), Category = "EiV|Geometry|Axis Aligned Box")
	static void EiVBoxToAABox(FBox Box, FEiVAxisAlignedBox AABox, FBox& OutBox, FEiVAxisAlignedBox& OutAABox);
	//Converts between an Unreal Engine Scalar and an Eigen Uniform Scaling type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Scalar To Uniform Scaling", Keywords = "EiV Eigen Scaling Uniform", AutoCreateRefTerm = "Scalar, Scaling"), Category = "EiV|Geometry|Uniform Scaling")
	static void EiVScalarToUniformScaling(double Scalar, FEiVUniformScaling Scaling, double& OutScalar, FEiVUniformScaling& OutScaling);
	//Converts between an Unreal Engine Vector2D and an Eigen Parameterized Line type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector2D To Parameterized Line", Keywords = "EiV Eigen Vector2D Parameterized Line", AutoCreateRefTerm = "Vector, Line"), Category = "EiV|Geometry|Parameterized Line")
	static void EiVVector2DToParameterizedLine(FVector2D Vector, FEiVParameterizedLine Line, FVector2D& OutVector, FEiVParameterizedLine& OutLine);
	//Converts between an Unreal Engine Vector and an Eigen Parameterized Line type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Vector To Parameterized Line", Keywords = "EiV Eigen Vector Parameterized Line", AutoCreateRefTerm = "Vector, Line"), Category = "EiV|Geometry|Parameterized Line")
	static void EiVVectorToParameterizedLine(FVector Vector, FEiVParameterizedLine Line, FVector& OutVector, FEiVParameterizedLine& OutLine);
	//Converts between an Unreal Engine Ray and an Eigen Parameterized Line type (Input types are inverted)
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Ray To Parameterized Line", Keywords = "EiV Eigen Ray Parameterized Line", AutoCreateRefTerm = "Origin, Direction, Line"), Category = "EiV|Geometry|Parameterized Line")
	static void EiVRayToParameterizedLine(FVector Origin, FVector Direction, FEiVParameterizedLine Line, FVector& OutOrigin, FVector& OutDirection, FEiVParameterizedLine& OutLine);

};
