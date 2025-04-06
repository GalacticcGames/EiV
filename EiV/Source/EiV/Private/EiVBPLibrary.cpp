// Copyright 2025, Galacticc Games. All rights reserved.

/* Licensed under MIT license. See LICENSE for full license text.
*
*        Created: 20th March 2025
*  Last Modified: 6th April 2025
*/

#include "EiVBPLibrary.h"
#include "EiV.h"

UEiVBPLibrary::UEiVBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

void UEiVBPLibrary::EiVAddMatrix(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& Matrix)
{
	if (A.Matrix.rows() == B.Matrix.rows() && A.Matrix.cols() == B.Matrix.cols()) {
		Matrix = FEiVDynamicMatrix(A.Matrix + B.Matrix);
	}
	else {
		Matrix = FEiVDynamicMatrix();
	}
}

void UEiVBPLibrary::EiVSubtractMatrix(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& Matrix)
{
	if (A.Matrix.rows() == B.Matrix.rows() && A.Matrix.cols() == B.Matrix.cols()) {
		Matrix = FEiVDynamicMatrix(A.Matrix - B.Matrix);
	}
	else {
		Matrix = FEiVDynamicMatrix();
	}
}

void UEiVBPLibrary::EiVScalarMultiplyMatrix(double s, FEiVDynamicMatrix A, FEiVDynamicMatrix& Matrix)
{
	Matrix = FEiVDynamicMatrix(A.Matrix * s);
}

void UEiVBPLibrary::EiVScalarDivideMatrix(FEiVDynamicMatrix A, double s, FEiVDynamicMatrix& Matrix)
{
	if (s != 0) {
		Matrix = FEiVDynamicMatrix(A.Matrix / s);
	}
	else {
		Matrix = FEiVDynamicMatrix();
	}
}

void UEiVBPLibrary::EiVTransposeMatrix(FEiVDynamicMatrix A, FEiVDynamicMatrix& Matrix)
{
	Matrix = FEiVDynamicMatrix(A.Matrix.transpose());
}

void UEiVBPLibrary::EiVConjugateMatrix(FEiVDynamicComplexMatrix A, FEiVDynamicComplexMatrix& Matrix)
{
	Matrix = FEiVDynamicComplexMatrix(A.Matrix.conjugate());
}

void UEiVBPLibrary::EiVAdjointMatrix(FEiVDynamicMatrix A, FEiVDynamicMatrix& Matrix)
{
	Matrix = FEiVDynamicMatrix(A.Matrix.adjoint());
}

void UEiVBPLibrary::EiVMatrixMultiplication(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& Matrix)
{
	if (A.Matrix.cols() == B.Matrix.rows()) {
		Matrix = FEiVDynamicMatrix(A.Matrix * B.Matrix);
	}
	else {
		Matrix = FEiVDynamicMatrix();
	}
}

void UEiVBPLibrary::EiVDotProduct(FEiVDynamicMatrix A, FEiVDynamicMatrix B, double& DotProduct)
{
	if (A.Matrix.cols() == B.Matrix.cols()) {
		EiVVectorXd ASpecific = A.Matrix.col(0);
		EiVVectorXd BSpecific = B.Matrix.col(0);
		DotProduct = ASpecific.dot(BSpecific);
	}
	else {
		DotProduct = 0;
	}
}

void UEiVBPLibrary::EiVCrossProduct(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& CrossProduct)
{
	if ((A.Matrix.size() == 9 || (A.Matrix.size() == 3 && A.Matrix.cols() == 1)) && (B.Matrix.size() == 9 || (B.Matrix.size() == 3 && B.Matrix.cols() == 1))) {
		EiVVector3d ASpecific = A.Matrix.col(0);
		EiVVector3d BSpecific = B.Matrix.col(0);
		CrossProduct = FEiVDynamicMatrix(ASpecific.cross(BSpecific));
	}
	else {
		CrossProduct = FEiVDynamicMatrix();
	}
}

void UEiVBPLibrary::EiVMatrixRows(FEiVDynamicMatrix A, int& Rows)
{
	Rows = A.Matrix.rows();
}

void UEiVBPLibrary::EiVMatrixColumns(FEiVDynamicMatrix A, int& Columns)
{
	Columns = A.Matrix.cols();
}

void UEiVBPLibrary::EiVMatrixSize(FEiVDynamicMatrix A, int& Size)
{
	Size = A.Matrix.size();
}

void UEiVBPLibrary::EiVMatrixSum(FEiVDynamicMatrix A, double& Sum)
{
	Sum = A.Matrix.sum();
}

void UEiVBPLibrary::EiVMatrixProduct(FEiVDynamicMatrix A, double& Product)
{
	Product = A.Matrix.prod();
}

void UEiVBPLibrary::EiVMatrixMean(FEiVDynamicMatrix A, double& Mean)
{
	Mean = A.Matrix.mean();
}

void UEiVBPLibrary::EiVMatrixTrace(FEiVDynamicMatrix A, double& Trace)
{
	Trace = A.Matrix.trace();
}

void UEiVBPLibrary::EiVMatrixMin(FEiVDynamicMatrix A, double& Minimum, int& Row, int& Column)
{
	std::ptrdiff_t r, c;
	Minimum = A.Matrix.minCoeff(&r, &c);
	Row = r;
	Column = c;
}

void UEiVBPLibrary::EiVMatrixMax(FEiVDynamicMatrix A, double& Maximum, int& Row, int& Column)
{
	std::ptrdiff_t r, c;
	Maximum = A.Matrix.maxCoeff(&r, &c);
	Row = r;
	Column = c;
}

void UEiVBPLibrary::EiVMatrixBlock(FEiVDynamicMatrix A, int32 StartRow, int32 StartCol, int32 BlockWidth, int32 BlockHeight, FEiVDynamicMatrix& Block)
{
	if (StartRow < A.Matrix.rows() && StartRow > 0 && StartCol < A.Matrix.cols() && StartCol > 0 &&
		BlockWidth > 0 && BlockHeight > 0 && BlockWidth + StartRow < A.Matrix.rows() && 
		BlockHeight + StartCol < A.Matrix.cols()) {
		Block = FEiVDynamicMatrix(A.Matrix.block(StartRow,StartCol,BlockWidth,BlockHeight));
	}
	else {
		Block = FEiVDynamicMatrix();
	}
}

void UEiVBPLibrary::EiVMatrixRow(FEiVDynamicMatrix A, int32 RowIndex, FEiVDynamicMatrix& Row)
{
	if (RowIndex >= 0 && RowIndex < A.Matrix.rows()) {
		Row = FEiVDynamicMatrix(A.Matrix.row(RowIndex));
	}
	else {
		Row = FEiVDynamicMatrix();
	}
}

void UEiVBPLibrary::EiVMatrixColumn(FEiVDynamicMatrix A, int32 ColIndex, FEiVDynamicMatrix& Column)
{
	if (ColIndex >= 0 && ColIndex < A.Matrix.cols()) {
		Column = FEiVDynamicMatrix(A.Matrix.col(ColIndex));
	}
	else {
		Column = FEiVDynamicMatrix();
	}
}

void UEiVBPLibrary::EiVGetMatrixElement(FEiVDynamicMatrix A, int32 RowIndex, int32 ColIndex, double& Element)
{
	if (ColIndex >= 0 && ColIndex < A.Matrix.cols() && RowIndex >= 0 && RowIndex < A.Matrix.rows()) {
		Element = A.Matrix.coeff(RowIndex,ColIndex);
	}
	else {
		Element = 0;
	}
}

void UEiVBPLibrary::EiVSetMatrixElement(FEiVDynamicMatrix A, int32 RowIndex, int32 ColIndex, double Element, FEiVDynamicMatrix& Matrix)
{
	if (ColIndex >= 0 && ColIndex < A.Matrix.cols() && RowIndex >= 0 && RowIndex < A.Matrix.rows()) {
		A.Matrix.coeffRef(RowIndex, ColIndex) = Element;
		Matrix = FEiVDynamicMatrix(A.Matrix);
	}
}

void UEiVBPLibrary::EiVMatrixReshape(FEiVDynamicMatrix A, int32 RowSize, int32 ColSize, FEiVDynamicMatrix& Reshaped)
{
	if (ColSize > 0 && RowSize > 0) {
		Reshaped = FEiVDynamicMatrix(A.Matrix.reshaped(RowSize, ColSize).eval());
	}
}

void UEiVBPLibrary::EiVColPivHHQR(FEiVDynamicMatrix A, FEiVDynamicMatrix B, FEiVDynamicMatrix& Solution)
{
	if (B.Matrix.rows() == A.Matrix.cols()) {
		Solution = FEiVDynamicMatrix(A.Matrix.colPivHouseholderQr().solve(B.Matrix.col(0)));
	}
	else {
		Solution = FEiVDynamicMatrix();
	}
}

void UEiVBPLibrary::EiVMatrixEigenvalues(FEiVDynamicMatrix A, EEiVBPFuncSuccess& Success, FEiVDynamicComplexMatrix& Solution)
{
	EiVEigenSolver<EiVMatrixXd> Solver(A.Matrix);
	if (Solver.info() != EiVComputationInfo::Success) {
		Success = EEiVBPFuncSuccess::FAILURE;
		Solution = FEiVDynamicComplexMatrix();
	}
	else {
		Success = EEiVBPFuncSuccess::SUCCESS;
		Solution = FEiVDynamicComplexMatrix(Solver.eigenvalues());
	}
}

void UEiVBPLibrary::EiVMatrixEigenvectors(FEiVDynamicMatrix A, EEiVBPFuncSuccess& Success, FEiVDynamicComplexMatrix& Solution)
{
	EiVEigenSolver<EiVMatrixXd> Solver(A.Matrix);
	if (Solver.info() != EiVComputationInfo::Success) {
		Success = EEiVBPFuncSuccess::FAILURE;
		Solution = FEiVDynamicComplexMatrix();
	}
	else {
		Success = EEiVBPFuncSuccess::SUCCESS;
		Solution = FEiVDynamicComplexMatrix(Solver.eigenvectors());
	}
}

void UEiVBPLibrary::EiVMatrixDeterminant(FEiVDynamicMatrix A, double& Determinant)
{
	Determinant = A.Matrix.determinant();
}

void UEiVBPLibrary::EiVMatrixInverse(FEiVDynamicMatrix A, FEiVDynamicMatrix& Inverse)
{
	if (A.Matrix.determinant() != 0) {
		Inverse = FEiVDynamicMatrix(A.Matrix.inverse());
	}
}

void UEiVBPLibrary::EiVMatrixRank(FEiVDynamicMatrix A, int& Rank)
{
	EiVFullPivLU<EiVMatrixXd> Lu(A.Matrix);
	Rank = Lu.rank();
}

void UEiVBPLibrary::EiVMatrixToString(FEiVDynamicMatrix A, FString& String)
{
	String += "{";
	for (int i = 0; i < A.Matrix.rows(); i++) {
		String += "\n [";
		for (int j = 0; j < A.Matrix.cols(); j++) {
			String += FString::SanitizeFloat(A.Matrix.coeff(i, j)) + (j != A.Matrix.cols() - 1 ? ", " : "");
		}
		String += "]";
	}
	String += "\n}";
}

void UEiVBPLibrary::EiVArrayGetElement(FEiVArray A, int Index, double& Element)
{
	Element = A.Array(Index);
}

void UEiVBPLibrary::EiVArraySetElement(UPARAM(ref)FEiVArray& A, int Index, double Element)
{
	A.Array(Index) = Element;
}

void UEiVBPLibrary::EiVArrayAdd(FEiVArray A, FEiVArray B, FEiVArray& Array)
{
	Array = FEiVArray();
	Array.Array = (A.Array + B.Array);
}

void UEiVBPLibrary::EiVArraySubtract(FEiVArray A, FEiVArray B, FEiVArray& Array)
{
	Array = FEiVArray();
	Array.Array = (A.Array - B.Array);
}

void UEiVBPLibrary::EiVArrayScalarMultiply(double s, FEiVArray A, FEiVArray& Array)
{
	Array = FEiVArray();
	Array.Array = (A.Array * s);
}

void UEiVBPLibrary::EiVArrayScalarAdd(FEiVArray A, double s, FEiVArray& Array)
{
	Array = FEiVArray();
	Array.Array = (A.Array + s);
}

void UEiVBPLibrary::EiVArrayScalarSubtract(FEiVArray A, double s, FEiVArray& Array)
{
	Array = FEiVArray();
	Array.Array = (A.Array - s);
}

void UEiVBPLibrary::EiVArrayMultiply(FEiVArray A, FEiVArray B, FEiVArray& Array)
{
	Array = FEiVArray();
	Array.Array = (A.Array * B.Array);
}

void UEiVBPLibrary::EiVArrayMin(FEiVArray A, FEiVArray B, FEiVArray& Array)
{
	Array = FEiVArray();
	if (A.Array.size() == B.Array.size()) {
		Array.Array = (A.Array.min(B.Array));
	}
}

void UEiVBPLibrary::EiVArrayMax(FEiVArray A, FEiVArray B, FEiVArray& Array)
{
	Array = FEiVArray();
	if (A.Array.size() == B.Array.size()) {
		Array.Array = (A.Array.max(B.Array));
	}
}

void UEiVBPLibrary::EiVArrayAbs(FEiVArray A, FEiVArray& Array)
{
	Array = FEiVArray();
	Array.Array = (A.Array.abs());
}

void UEiVBPLibrary::EiVArrayToString(FEiVArray A, FString& String)
{
	String += "[";
	for (int i = 0; i < A.Array.rows(); i++) {
		String += FString::SanitizeFloat(A.Array.coeff(i)) + (i != A.Array.rows() - 1 ? ", " : "");
	}
	String += "]";
}

void UEiVBPLibrary::EiVMakeDynamicComplexMatrix(TArray<FEiVComplexNumber> Array, int32 Rows, int32 Cols, FEiVDynamicComplexMatrix& Matrix)
{
	Matrix = FEiVDynamicComplexMatrix(Array, Rows, Cols);
}

void UEiVBPLibrary::EiVDynamicComplexMatrixToArray(FEiVDynamicComplexMatrix Matrix, TArray<FEiVComplexNumber>& Array)
{
	Array = TArray< FEiVComplexNumber>();
	for (int i = 0; i < Matrix.Matrix.rows(); i++) {
		for (int j = 0; j < Matrix.Matrix.cols(); j++) {
			Array.Add(FEiVComplexNumber(Matrix.Matrix.coeff(i, j)));
		}
	}
}

void UEiVBPLibrary::EiVStripReals(FEiVDynamicComplexMatrix Matrix, FEiVDynamicMatrix& ImaginaryMatrix)
{
	EiVMatrixXd Mat(Matrix.Matrix.rows(), Matrix.Matrix.cols());
	for (int i = 0; i < Matrix.Matrix.rows(); i++) {
		for (int j = 0; j < Matrix.Matrix.cols(); j++) {
			Mat.coeffRef(i, j) = Matrix.Matrix.coeff(i, j).imag();
		}
	}
	ImaginaryMatrix = FEiVDynamicMatrix(Mat);
}

void UEiVBPLibrary::EiVStripImaginary(FEiVDynamicComplexMatrix Matrix, FEiVDynamicMatrix& RealMatrix)
{
	EiVMatrixXd Mat(Matrix.Matrix.rows(), Matrix.Matrix.cols());
	for (int i = 0; i < Matrix.Matrix.rows(); i++) {
		for (int j = 0; j < Matrix.Matrix.cols(); j++) {
			Mat.coeffRef(i, j) = Matrix.Matrix.coeff(i, j).real();
		}
	}
	RealMatrix = FEiVDynamicMatrix(Mat);
}

void UEiVBPLibrary::EiVDynamicMatrixToArray(FEiVDynamicMatrix Matrix, TArray<double>& Array)
{
	Array = TArray<double>();
	for (int i = 0; i < Matrix.Matrix.rows(); i++) {
		for (int j = 0; j < Matrix.Matrix.cols(); j++) {
			Array.Add(Matrix.Matrix.coeff(i, j));
		}
	}
}

void UEiVBPLibrary::EiVMakeDynamicMatrix(TArray<double> Array, int32 Rows, int32 Cols, FEiVDynamicMatrix& Matrix)
{
	Matrix = FEiVDynamicMatrix(Array, Rows, Cols);
}

void UEiVBPLibrary::EiVMakeDynamicVector(TArray<double> Array, int32 Cols, FEiVDynamicMatrix& Vector)
{
	Vector = FEiVDynamicMatrix(FEiVDynamicVector(Array,Cols).Vector);
}

void UEiVBPLibrary::EiVMakeRandomDynamicMatrix(int32 Rows, int32 Cols, FEiVDynamicMatrix& Matrix)
{
	Matrix = FEiVDynamicMatrix(EiVMatrixXd::Random(Rows, Cols));
}

void UEiVBPLibrary::EiVMakeRandomDynamicVector(int32 Cols, FEiVDynamicMatrix& Vector)
{
	Vector = FEiVDynamicMatrix(FEiVDynamicVector(Cols).Vector);
}

void UEiVBPLibrary::EiVSetEigenThreads(int32 Threads)
{
	FEiVHelper::SetEigenThreads(Threads);
}

void UEiVBPLibrary::EiVGetEigenThreads(int32& Threads)
{
	Threads = FEiVHelper::GetEigenThreads();
}

void UEiVBPLibrary::EiVVector2DToComplex(FVector2D Vector, bool AsPhasor, FEiVComplexNumber ComplexNumber, FVector2D& OutVector, FEiVComplexNumber& OutComplexNumber)
{
	OutVector = FEiVHelper::ComplexToVector2D(ComplexNumber.Complex, AsPhasor);
	OutComplexNumber = FEiVComplexNumber(Vector, AsPhasor);
}

void UEiVBPLibrary::EiVNullMatrix(FEiVNullMatrix& NullMatrix)
{
	NullMatrix = FEiVNullMatrix();
}

void UEiVBPLibrary::EiVNullMatrixAsDynamic(FEiVNullMatrix NullMatrix, FEiVDynamicMatrix& Matrix)
{
	Matrix = FEiVDynamicMatrix(NullMatrix.Matrix);
}

void UEiVBPLibrary::EiVArrayToEigenArray(TArray<double> Array, FEiVArray EigenArray, TArray<double>& OutArray, FEiVArray& OutEigenArray)
{
	OutArray = FEiVHelper::TArrayFromDynamicArray<double>(EigenArray.Array);
	OutEigenArray = FEiVArray(Array);
}

void UEiVBPLibrary::EiVVector2DToEiVVector(FVector2D Vector, FEiVVector EiVVector, FVector2D& OutVector, FEiVVector& OutEiVVector)
{
	FVector4 Vec = FEiVHelper::FVectorFromVector(EiVVector.Vector);
	OutVector = FVector2D(Vec.X,Vec.Y);
	OutEiVVector = FEiVVector(Vector);
}

void UEiVBPLibrary::EiVVectorToEiVVector(FVector Vector, FEiVVector EiVVector, FVector& OutVector, FEiVVector& OutEiVVector)
{
	FVector4 Vec = FEiVHelper::FVectorFromVector(EiVVector.Vector);
	OutVector = FVector(Vec.X, Vec.Y,Vec.Z);
	OutEiVVector = FEiVVector(Vector);
}

void UEiVBPLibrary::EiVVectorToDynamicVector(FEiVVector Vector, FEiVDynamicMatrix& OutDynamicVector)
{
	OutDynamicVector = FEiVDynamicMatrix(Vector.Vector);
}

void UEiVBPLibrary::EiVVector4ToEiVVector(FVector4 Vector, FEiVVector EiVVector, FVector4& OutVector, FEiVVector& OutEiVVector)
{
	OutVector = FEiVHelper::FVectorFromVector(EiVVector.Vector);
	OutEiVVector = FEiVVector(Vector);
}

void UEiVBPLibrary::EiVVector2DToRowVector(FVector2D Vector, FEiVRowVector RowVector, FVector2D& OutVector, FEiVRowVector& OutRowVector)
{
	FVector4 Vec = FEiVHelper::FVectorFromRowVector(RowVector.Vector);
	OutVector = FVector2D(Vec.X, Vec.Y);
	OutRowVector = FEiVRowVector(Vector);
}

void UEiVBPLibrary::EiVVectorToRowVector(FVector Vector, FEiVRowVector RowVector, FVector& OutVector, FEiVRowVector& OutRowVector)
{
	FVector4 Vec = FEiVHelper::FVectorFromRowVector(RowVector.Vector);
	OutVector = FVector(Vec.X, Vec.Y, Vec.Z);
	OutRowVector = FEiVRowVector(Vector);
}

void UEiVBPLibrary::EiVRowVectorToDynamicVector(FEiVRowVector Vector, FEiVDynamicMatrix& OutDynamicVector)
{
	OutDynamicVector = FEiVDynamicMatrix(Vector.Vector);
}

void UEiVBPLibrary::EiVVector4ToRowVector(FVector4 Vector, FEiVRowVector RowVector, FVector4& OutVector, FEiVRowVector& OutRowVector)
{
	OutVector = FEiVHelper::FVectorFromRowVector(RowVector.Vector);
	OutRowVector = FEiVRowVector(Vector);
}

void UEiVBPLibrary::EiVMatrixToEigenMatrix(FMatrix Matrix, FEiVMatrix EigenMatrix, FMatrix& OutMatrix, FEiVMatrix& OutEigenMatrix)
{
	OutMatrix = FEiVHelper::FMatrixFromMatrix(EigenMatrix.Matrix);
	OutEigenMatrix = FEiVMatrix(Matrix);
}

void UEiVBPLibrary::EiVEigenMatrixToDynamicMatrix(FEiVMatrix Matrix, FEiVDynamicMatrix& OutDynamicMatrix)
{
	OutDynamicMatrix = FEiVDynamicMatrix(Matrix.Matrix);
}

void UEiVBPLibrary::EiVVector2DToJacobiRotation(FVector2D Vector, FEiVJacobiRotation JacobiRotation, FVector2D& OutVector, FEiVJacobiRotation& OutJacobiRotation)
{
	OutVector = FEiVHelper::Vector2DFromJacobiRotation(JacobiRotation.Rotation);
	OutJacobiRotation = FEiVJacobiRotation(Vector);
}

void UEiVBPLibrary::EiVVectorToTriplet(FVector Vector, FEiVTriplet Triplet, FVector& OutVector, FEiVTriplet& OutTriplet)
{
	OutVector = FEiVHelper::VectorFromTriplet(Triplet.Triplet);
	OutTriplet = FEiVTriplet(Vector);
}

void UEiVBPLibrary::EiVVector2DToSparseVector(FVector2D Vector, FEiVSparseVector SparseVector, FVector2D& OutVector, FEiVSparseVector& OutSparseVector)
{
	FVector4 Vec = FEiVHelper::VectorFromSparseVector(SparseVector.Vector);
	OutVector = FVector2D(Vec.X, Vec.Y);
	OutSparseVector = FEiVSparseVector(Vector);
}

void UEiVBPLibrary::EiVVectorToSparseVector(FVector Vector, FEiVSparseVector SparseVector, FVector& OutVector, FEiVSparseVector& OutSparseVector)
{
	FVector4 Vec = FEiVHelper::VectorFromSparseVector(SparseVector.Vector);
	OutVector = FVector(Vec.X, Vec.Y, Vec.Z);
	OutSparseVector = FEiVSparseVector(Vector);
}

void UEiVBPLibrary::EiVVector4ToSparseVector(FVector4 Vector, FEiVSparseVector SparseVector, FVector4& OutVector, FEiVSparseVector& OutSparseVector)
{
	OutVector = FEiVHelper::VectorFromSparseVector(SparseVector.Vector);
	OutSparseVector = FEiVSparseVector(Vector);
}

void UEiVBPLibrary::EiVMatrixToSparseMatrix(FMatrix Matrix, FEiVSparseMatrix SparseMatrix, FMatrix& OutMatrix, FEiVSparseMatrix& OutSparseMatrix)
{
	OutMatrix = FEiVHelper::FMatrixFromSparseMatrix(SparseMatrix.Matrix);
	OutSparseMatrix = FEiVSparseMatrix(Matrix);
}

void UEiVBPLibrary::EiVArrayToSparseMatrix(TArray<double> Array, int32 Rows, int32 Cols, FEiVSparseMatrix SparseMatrix, TArray<double>& OutArray, FEiVSparseMatrix& OutSparseMatrix)
{
	OutArray = FEiVHelper::TArrayFromSparseMatrix(SparseMatrix.Matrix);
	OutSparseMatrix = FEiVSparseMatrix(Array,Rows,Cols);
}

void UEiVBPLibrary::EiVQuatToQuaternion(FQuat Quat, FEiVQuaternion Quaternion, FQuat& OutQuat, FEiVQuaternion& OutQuaternion)
{
	OutQuat = FEiVHelper::QuatFromQuaternion(Quaternion.Quat);
	OutQuaternion = FEiVQuaternion(Quat);
}

void UEiVBPLibrary::EiVQuatToAngleAxis(FQuat Quat, FEiVAngleAxis AngleAxis, FQuat& OutQuat, FEiVAngleAxis& OutAngleAxis)
{
	OutQuat = FEiVHelper::QuatFromAngleAxis(AngleAxis.AngleAxis);
	OutAngleAxis = FEiVAngleAxis(Quat);
}

void UEiVBPLibrary::EiVRotatorToAngleAxis(FRotator Rotator, FEiVAngleAxis AngleAxis, FRotator& OutRotator, FEiVAngleAxis& OutAngleAxis)
{
	OutRotator = FEiVHelper::RotatorFromAngleAxis(AngleAxis.AngleAxis);
	OutAngleAxis = FEiVAngleAxis(Rotator);
}

void UEiVBPLibrary::EiVRotatorToRotation2D(FRotator Rotator, FEiVRotation2D Rotation2D, FRotator& OutRotator, FEiVRotation2D& OutRotation2D)
{
	OutRotator = FEiVHelper::RotatorFrom2DRotation(Rotation2D.Rotation);
	OutRotation2D = FEiVRotation2D(Rotator);
}

void UEiVBPLibrary::EiVVector2DToTranslation(FVector2D Vector, FEiVTranslation Translation, FVector2D& OutVector, FEiVTranslation& OutTranslation)
{
	FVector Vec = FEiVHelper::VectorFromTranslation(Translation.Translation);
	OutVector = FVector2D(Vec.X, Vec.Y);
	OutTranslation = FEiVTranslation(Vector);
}

void UEiVBPLibrary::EiVVectorToTranslation(FVector Vector, FEiVTranslation Translation, FVector& OutVector, FEiVTranslation& OutTranslation)
{
	OutVector = FEiVHelper::VectorFromTranslation(Translation.Translation);
	OutTranslation = FEiVTranslation(Vector);
}

void UEiVBPLibrary::EiVBox2DToAABox(FBox2D Box, FEiVAxisAlignedBox AABox, FBox2D& OutBox, FEiVAxisAlignedBox& OutAABox)
{
	FBox Bx = FEiVHelper::FBoxFromAABox(AABox.AABox);
	OutBox = FBox2D(FVector2D(Bx.Min.X,Bx.Min.Y), FVector2D(Bx.Max.X, Bx.Max.Y));
	OutAABox = FEiVAxisAlignedBox(Box);
}

void UEiVBPLibrary::EiVBoxToAABox(FBox Box, FEiVAxisAlignedBox AABox, FBox& OutBox, FEiVAxisAlignedBox& OutAABox)
{
	OutBox = FEiVHelper::FBoxFromAABox(AABox.AABox);
	OutAABox = FEiVAxisAlignedBox(Box);
}

void UEiVBPLibrary::EiVScalarToUniformScaling(double Scalar, FEiVUniformScaling Scaling, double& OutScalar, FEiVUniformScaling& OutScaling)
{
	OutScalar = FEiVHelper::ScalarFromUniformScaling(Scaling.Scaling);
	OutScaling = FEiVUniformScaling(Scalar);
}

void UEiVBPLibrary::EiVVector2DToParameterizedLine(FVector2D Vector, FEiVParameterizedLine Line, FVector2D& OutVector, FEiVParameterizedLine& OutLine)
{
	FVector Vec = FEiVHelper::VectorFromParameterizedLine(Line.Line);
	OutVector = FVector2D(Vec.X,Vec.Y);
	OutLine = FEiVParameterizedLine(Vector);
}

void UEiVBPLibrary::EiVVectorToParameterizedLine(FVector Vector, FEiVParameterizedLine Line, FVector& OutVector, FEiVParameterizedLine& OutLine)
{
	OutVector = FEiVHelper::VectorFromParameterizedLine(Line.Line);
	OutLine = FEiVParameterizedLine(Vector);
}

void UEiVBPLibrary::EiVRayToParameterizedLine(FVector Origin, FVector Direction, FEiVParameterizedLine Line, FVector& OutOrigin, FVector& OutDirection, FEiVParameterizedLine& OutLine)
{
	FRay Ray = FRay(Origin, Direction);
	FRay OutRay = FEiVHelper::RayFromParameterizedLine(Line.Line);
	OutOrigin = OutRay.Origin;
	OutDirection = OutRay.Direction;
	OutLine = FEiVParameterizedLine(Ray);
}
