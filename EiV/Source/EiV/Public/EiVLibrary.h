// Copyright Galacticc Games 2025. All rights reserved.

/* Licensed under MIT license. See LICENSE for full license text.
*
*        Created: 20th March 2025
*  Last Modified: 21st March 2025
*/

#pragma once

#include "CoreMinimal.h"
#if defined(_WIN64) || defined(_WIN32)
#include <Windows/WindowsPlatformCompilerPreSetup.h>
#endif
#if defined(__APPLE__) && defined(TARGET_OS_MAC)
#include <Apple/ApplePlatformCompilerPreSetup.h>
#endif
#ifdef __linux__
#include <Unix/UnixPlatformCompilerPreSetup.h>
#endif
#include "EiVLibrary.generated.h"

// Swath macros that include several modules or similar/grouped modules
#ifdef EIV_INCLUDE_DENSE_MATRIX_ARRAY
#ifndef EIV_INCLUDE_CORE
#define EIV_INCLUDE_CORE 
#endif
#ifndef EIV_INCLUDE_JACOBI
#define EIV_INCLUDE_JACOBI 
#endif
#ifndef EIV_INCLUDE_HOUSEHOLDER
#define EIV_INCLUDE_HOUSEHOLDER 
#endif
#endif
#ifdef EIV_INCLUDE_DENSE_LINEAR_PROBLEMS
#ifndef EIV_INCLUDE_CHOLESKY
#define EIV_INCLUDE_CHOLESKY 
#endif
#ifndef EIV_INCLUDE_LU
#define EIV_INCLUDE_LU
#endif
#ifndef EIV_INCLUDE_QR
#define EIV_INCLUDE_QR
#endif
#ifndef EIV_INCLUDE_SVD
#define EIV_INCLUDE_SVD
#endif
#ifndef EIV_INCLUDE_EIGENVALUES
#define EIV_INCLUDE_EIGENVALUES
#endif
#endif
#ifdef EIV_INCLUDE_SPARSE_LINEAR_ALGEBRA
#ifndef EIV_INCLUDE_SPARSECORE
#define EIV_INCLUDE_SPARSECORE
#endif
#ifndef EIV_INCLUDE_ORDERINGMETHODS
#define EIV_INCLUDE_ORDERINGMETHODS
#endif
#ifndef EIV_INCLUDE_SPARSECHOLESKY
#define EIV_INCLUDE_SPARSECHOLESKY
#endif
#ifndef EIV_INCLUDE_SPARSELU
#define EIV_INCLUDE_SPARSELU
#endif
#ifndef EIV_INCLUDE_SPARSEQR
#define EIV_INCLUDE_SPARSEQR
#endif
#ifndef EIV_INCLUDE_ITERATIVELINEARSOLVERS
#define EIV_INCLUDE_ITERATIVELINEARSOLVERS
#endif
#endif

//Double checking definition
#ifndef EIGEN_MPL2_ONLY
#define EIGEN_MPL2_ONLY
#endif
// Import Eigen with safe checks
PRAGMA_DEFAULT_VISIBILITY_START
THIRD_PARTY_INCLUDES_START
// IMPORTANT: Have the file including these libraries define which modules
// it wants to load by defining these macros before including this .h file
#ifdef EIV_INCLUDE_CORE
#include <Eigen/Core>
#endif
#ifdef EIV_INCLUDE_JACOBI
#include <Eigen/Jacobi>
#endif
#ifdef EIV_INCLUDE_HOUSEHOLDER
#include <Eigen/Householder>
#endif
#ifdef EIV_INCLUDE_CHOLESKY
#include <Eigen/Cholesky>
#endif
#ifdef EIV_INCLUDE_LU
#include <Eigen/LU>
#endif
#ifdef EIV_INCLUDE_QR
#include <Eigen/QR>
#endif
#ifdef EIV_INCLUDE_SVD
#include <Eigen/SVD>
#endif
#ifdef EIV_INCLUDE_EIGENVALUES
#include <Eigen/Eigenvalues>
#endif
#ifdef EIV_INCLUDE_SPARSECORE
#include <Eigen/SparseCore>
#endif
#ifdef EIV_INCLUDE_ORDERINGMETHODS
#include <Eigen/OrderingMethods>
#endif
#ifdef EIV_INCLUDE_SPARSECHOLESKY
#include <Eigen/SparseCholesky>
#endif
#ifdef EIV_INCLUDE_SPARSELU
#include <Eigen/SparseLU>
#endif
#ifdef EIV_INCLUDE_SPARSEQR
#include <Eigen/SparseQR>
#endif
#ifdef EIV_INCLUDE_ITERATIVELINEARSOLVERS
#include <Eigen/IterativeLinearSolvers>
#endif
#ifdef EIV_INCLUDE_GEOMETRY
#include <Eigen/Geometry>
#endif
THIRD_PARTY_INCLUDES_END
PRAGMA_DEFAULT_VISIBILITY_END

// Define this before the include statement for this file to have the typedefs and extra 
// utility removed so this class becomes a pure include for whatever Eigen modules were specified
#ifndef EIV_NO_UTILITY

// Typedefs for easy UE C++ to help resolve potential naming similarities
// these resolve to structs for blueprints to handle UPROPERTY versions

#ifdef EIGEN_CORE_H
// === Enums

typedef Eigen::AccessorLevels        EiVAccessorLevels;
typedef Eigen::Action                EiVAction;
typedef Eigen::AlignmentType         EiVAlignmentType;
typedef Eigen::AmbiVectorMode        EiVAmbiVectorMode;
typedef Eigen::ComputationInfo       EiVComputationInfo;
typedef Eigen::DecompositionOptions  EiVDecompositionOptions;
typedef Eigen::DirectionType         EiVDirectionType;
typedef Eigen::NaNPropagationOptions EiVNaNPropagationOptions;
typedef Eigen::QRPreconditioners     EiVQRPreconditioners;
typedef Eigen::SideType              EiVSideType;
typedef Eigen::SpecializedType       EiVSpecializedType;
typedef Eigen::StorageOptions        EiVStorageOptions;
typedef Eigen::TransformTraits       EiVTransformTraits;
typedef Eigen::TraversalType         EiVTraversalType;
typedef Eigen::UnrollingType         EiVUnrollingType;
typedef Eigen::UpLoType              EiVUpLoType;

// === Classes

template<typename Derived>                                                                  using EiVArrayBase        = Eigen::ArrayBase<Derived>;
template<typename ExpressionType>                                                           using EiVArrayWrapper     = Eigen::ArrayWrapper<ExpressionType>;
template<typename Derived>                                                                  using EvIBaseExpr         = Eigen::symbolic::BaseExpr<Derived>;
template<typename XprType, int BlockRows = -1, int BlockCols = -1, bool InnerPanel = false> using EiVBlock            = Eigen::Block< XprType, BlockRows, BlockCols, InnerPanel>;
template<typename XprType>                                                                  using EiVCommaInitializer = Eigen::CommaInitializer<XprType>;
template<typename BinaryOp, typename LhsType, typename RhsType>                                  using EiVCwiseBinary    = Eigen::CwiseBinaryOp<BinaryOp,LhsType,RhsType>;
template<typename NullaryOp, typename PlainObjectType>                                           using EiVCwiseNullaryOp = Eigen::CwiseNullaryOp<NullaryOp,PlainObjectType>;
template<typename TernaryOp, typename Arg1Type, typename Arg2Type, typename Arg3Type>            using EiVCwiseTernaryOp = Eigen::CwiseTernaryOp<TernaryOp, Arg1Type, Arg2Type, Arg3Type>;
template<typename UnaryOp, typename XprType>                                                     using EiVCwiseUnaryOp   = Eigen::CwiseUnaryOp<UnaryOp,XprType>;
template<typename ViewOp, typename MatrixType>                                                   using EiVCwiseUnaryView = Eigen::CwiseUnaryView<ViewOp, MatrixType>;
template<typename Derived>                                                                       using EiVDenseBase                      = Eigen::DenseBase<Derived>;
template<typename Derived,int Level>                                                             using EiVDenseCoeffsBase                = Eigen::DenseCoeffsBase<Derived,Level>;
template<typename Derived>                                                                       using EiVDenseCoeffsBaseReadOnly        = Eigen::DenseCoeffsBase<Derived, 0>;
template<typename Derived>                                                                       using EiVDenseCoeffsBaseReadWrite       = Eigen::DenseCoeffsBase<Derived, 1>;
template<typename Derived>                                                                       using EiVDenseCoeffsBaseDirectReadOnly  = Eigen::DenseCoeffsBase<Derived, 2>;
template<typename Derived>                                                                       using EiVDenseCoeffsBaseDirectReadWrite = Eigen::DenseCoeffsBase<Derived, 3>;
template<typename MatrixType, int DiagIndex = 0>                                                 using EiVDiagonal           = Eigen::Diagonal<MatrixType,DiagIndex>;
template<typename Scalar, int SizeAtCompileTime, int MaxSizeAtCompileTime = SizeAtCompileTime>   using EiVDiagonalMatrix     = Eigen::DiagonalMatrix<Scalar,SizeAtCompileTime,MaxSizeAtCompileTime>;
template<typename DiagonalVectorType>                                                            using EiVDiagonalWrapper    = Eigen::DiagonalWrapper<DiagonalVectorType>;
template<typename Derived>                                                                       using EiVEigenBase          = Eigen::EigenBase<Derived>;
template<typename ExpressionType>                                                                using EiVForceAlignedAccess = Eigen::ForceAlignedAccess<ExpressionType>;
template<typename XprType, typename RowIndices, typename ColIndices>                             using EiVIndexedView        = Eigen::IndexedView<XprType, RowIndices, ColIndices>;
template<typename PlainObjectType, int MapOptions = 0, typename StrideType = Eigen::Stride<0,0>> using EiVMap                = Eigen::Map<PlainObjectType,MapOptions,StrideType>;
template<typename Derived>                                                                               using EiVMatrixBase         = Eigen::MatrixBase<Derived>;
template<typename ExpressionType>                                                                        using EiVMatrixWrapper      = Eigen::MatrixWrapper<ExpressionType>;
template<typename ExpressionType>                                                                        using EiVNestByValue        = Eigen::NestByValue<ExpressionType>;
template<typename ExpressionType, template<typename> class StorageBase>                                  using EiVNoAlias            = Eigen::NoAlias<ExpressionType,StorageBase>;
template<typename T>                                                                                     using EiVNumTraits          = Eigen::NumTraits<T>;
template<typename MatrixType, typename MemberOp, int Direction>                                          using EiVPartialReduxExpr   = Eigen::PartialReduxExpr<MatrixType,MemberOp,Direction>;
template<typename Derived>                                                                               using EiVPermutationBase    = Eigen::PermutationBase<Derived>;
template<int SizeAtCompileTime,int MaxSizeAtCompileTime = SizeAtCompileTime,typename StorageIndex = int> using EiVPermutationMatrix  = Eigen::PermutationMatrix<SizeAtCompileTime, MaxSizeAtCompileTime, StorageIndex>;
template<typename IndicesType>                                                                           using EiVPermutationWrapper = Eigen::PermutationWrapper<IndicesType>;
template<typename Derived>                                                                               using EiVPlainObjectBase    = Eigen::PlainObjectBase<Derived>;
template<typename Lhs,typename Rhs,int Option = 0>                                                       using EiVProduct            = Eigen::Product<Lhs,Rhs,Option>;
template<typename MatrixType,int RowFactor,int ColFactor>                                                           using EiVReplicate            = Eigen::Replicate<MatrixType,RowFactor,ColFactor>;
template<typename XprType,int Rows = -1,int Cols = -1,int Order = 0>                                                using EiVReshaped             = Eigen::Reshaped<XprType,Rows,Cols,Order>;
template<typename MatrixType, int Direction = 2>                                                                    using EiVReverse              = Eigen::Reverse<MatrixType,Direction>;
template<typename ScalarA,typename ScalarB,typename BinaryOp = Eigen::internal::scalar_product_op<ScalarA,ScalarB>> using EiVScalarBinaryOpTraits = Eigen::ScalarBinaryOpTraits<ScalarA,ScalarB,BinaryOp>;
template<typename ConditionMatrixType,typename ThenMatrixType,typename ElseMatrixType>                              using EiVSelect               = Eigen::Select<ConditionMatrixType,ThenMatrixType,ElseMatrixType>;
template<typename MatrixType,uint32 UpLo>                                                                           using EiVSelfAdjointView      = Eigen::SelfAdjointView<MatrixType,UpLo>;
template<typename Decomposition,typename RhsType>                                                                   using EiVSolve                = Eigen::Solve<Decomposition,RhsType>;
template<int OuterStrideAtCompileTime,int InnerStrideAtCompileTime>                                                 using EiVStride               = Eigen::Stride<OuterStrideAtCompileTime,InnerStrideAtCompileTime>;
template<typename MatrixType>                                                                                       using EiVTranspose            = Eigen::Transpose<MatrixType>;
template<int SizeAtCompileTime,int MaxSizeAtCompileTime = SizeAtCompileTime,typename StorageIndex = int>            using EiVTranspositions       = Eigen::Transpositions<SizeAtCompileTime, MaxSizeAtCompileTime, StorageIndex>;
template<typename Derived>																							using EiVTriangularBase       = Eigen::TriangularBase<Derived>;
template<typename MatrixType,uint32 Mode>																			using EiVTriangularView       = Eigen::TriangularView<MatrixType,Mode>;
template<typename VectorType, int Size = -1>																		using EiVVectorBlock          = Eigen::VectorBlock<VectorType,Size>;
template<typename ExpressionType, int Direction>																	using EiVVectorwiseOp         = Eigen::VectorwiseOp<ExpressionType,Direction>;
template<typename ExpressionType>																					using EiVWithFormat           = Eigen::WithFormat<ExpressionType>;
template<typename PlainObjectType, int Options = 0, typename StrideType = typename Eigen::internal::conditional<PlainObjectType::isVectorAtCompileTime, Eigen::InnerStride<1>, Eigen::OuterStride<>>::type>                         using EiVRef                = Eigen::Ref<PlainObjectType, Options, StrideType>;
template<typename Derived, int Level = Eigen::internal::accessors_level<Derived>::has_write_access ? Eigen::WriteAccessors : Eigen::ReadOnlyAccessors>                                                                              using EiVMapBase            = Eigen::MapBase<Derived, Level>;
template<typename Scalar, int Rows, int Cols, int Options = Eigen::AutoAlign | ((Rows == 1 && Cols != 1) ? Eigen::RowMajor : (Cols == 1 && Rows != 1) ? Eigen::ColMajor : Eigen::ColMajor), int MaxRows = Rows, int MaxCols = Cols> using EiVMatrix             = Eigen::Matrix<Scalar, Rows, Cols, Options, MaxRows, MaxCols>;
template<typename Scalar, int Rows, int Cols, int Options = Eigen::AutoAlign | ((Rows == 1 && Cols != 1) ? Eigen::RowMajor : (Cols == 1 && Rows != 1) ? Eigen::ColMajor : Eigen::ColMajor), int MaxRows = Rows, int MaxCols = Cols> using EiVArray              = Eigen::Array<Scalar, Rows, Cols, Options, MaxRows, MaxCols>;
template<typename FirstType = Eigen::Index, typename SizeType = Eigen::Index, typename IncrType = Eigen::internal::FixedInt<1>>                                                                                                     using EiVArithmeticSequence = Eigen::ArithmeticSequence<FirstType, SizeType, IncrType>;

typedef Eigen::IOFormat EiVIOFormat;

// === Concise Typedefs

#define MAKE_COMMON_TYPEDEFS(Name,Dim,Dim2,DimName)                      \
typedef EiVMatrix<std::complex<double>,Dim,Dim2> EiV##Name##DimName##cd; \
typedef EiVMatrix<std::complex<float>,Dim,Dim2>  EiV##Name##DimName##cf; \
typedef EiVMatrix<double,Dim,Dim2>               EiV##Name##DimName##d;  \
typedef EiVMatrix<float,Dim,Dim2>                EiV##Name##DimName##f;  \
typedef EiVMatrix<int,Dim,Dim2>                  EiV##Name##DimName##i;  \

#define MAKE_MATRIX_COMMON_TYPEDEFS(L,W,LName,WName)                     \
template<typename Type>                                                  \
using EiVMatrix##LName##WName = EiVMatrix<Type,L,W>;                     \
typedef EiVMatrix<std::complex<double>,L,W> EiVMatrix##LName##WName##cd; \
typedef EiVMatrix<std::complex<float>,L,W>  EiVMatrix##LName##WName##cf; \
typedef EiVMatrix<double,L,W>               EiVMatrix##LName##WName##d;  \
typedef EiVMatrix<float,L,W>                EiVMatrix##LName##WName##f;  \
typedef EiVMatrix<int,L,W>                  EiVMatrix##LName##WName##i;  \

const int EiVDynamic = Eigen::Dynamic;

template<typename Type> using EiVArray2          = EiVArray<Type, 2, 1>;
template<typename Type> using EiVArray22         = EiVArray<Type, 2, 2>;
template<typename Type> using EiVArray2X         = EiVArray<Type, 2, EiVDynamic>;
template<typename Type> using EiVArray3          = EiVArray<Type, 3, 1>;
template<typename Type> using EiVArray33         = EiVArray<Type, 3, 3>;
template<typename Type> using EiVArray3X         = EiVArray<Type, 3, EiVDynamic>;
template<typename Type> using EiVArray4          = EiVArray<Type, 4, 1>;
template<typename Type> using EiVArray44         = EiVArray<Type, 4, 4>;
template<typename Type> using EiVArray4X         = EiVArray<Type, 4, EiVDynamic>;
template<typename Type> using EiVArrayX          = EiVArray<Type, EiVDynamic, 1>;
template<typename Type> using EiVArrayX2         = EiVArray<Type, EiVDynamic, 2>;
template<typename Type> using EiVArrayX3         = EiVArray<Type, EiVDynamic, 3>;
template<typename Type> using EiVArrayX4         = EiVArray<Type, EiVDynamic, 4>;
template<typename Type> using EiVArrayXX         = EiVArray<Type, EiVDynamic, EiVDynamic>;
template<typename Type,int Size> using EiVVector = EiVMatrix<Type, Size, 1>;
template<typename Type> using EiVVector2         = EiVVector<Type, 2>;
template<typename Type> using EiVVector3         = EiVVector<Type, 3>;
template<typename Type> using EiVVector4         = EiVVector<Type, 4>;
template<typename Type> using EiVVectorX         = EiVVector<Type, EiVDynamic>;
MAKE_COMMON_TYPEDEFS(Vector,          2, 1, 2);
MAKE_COMMON_TYPEDEFS(Vector,          3, 1, 3);
MAKE_COMMON_TYPEDEFS(Vector,          4, 1, 4);
MAKE_COMMON_TYPEDEFS(Vector, EiVDynamic, 1, X);
template<typename Type, int Size> using EiVRowVector = EiVMatrix<Type, 1, Size>;
template<typename Type> using EiVRowVector2          = EiVRowVector<Type, 2>;
template<typename Type> using EiVRowVector3          = EiVRowVector<Type, 3>;
template<typename Type> using EiVRowVector4          = EiVRowVector<Type, 4>;
template<typename Type> using EiVRowVectorX          = EiVRowVector<Type, EiVDynamic>;
MAKE_COMMON_TYPEDEFS(RowVector, 1,          2, 2);
MAKE_COMMON_TYPEDEFS(RowVector, 1,          3, 3);
MAKE_COMMON_TYPEDEFS(RowVector, 1,          4, 4);
MAKE_COMMON_TYPEDEFS(RowVector, 1, EiVDynamic, X);
MAKE_MATRIX_COMMON_TYPEDEFS(         2,          2, 2,  );
MAKE_MATRIX_COMMON_TYPEDEFS(         2, EiVDynamic, 2, X);
MAKE_MATRIX_COMMON_TYPEDEFS(         3,          3, 3,  );
MAKE_MATRIX_COMMON_TYPEDEFS(         3, EiVDynamic, 3, X);
MAKE_MATRIX_COMMON_TYPEDEFS(         4,          4, 4,  );
MAKE_MATRIX_COMMON_TYPEDEFS(         4, EiVDynamic, 4, X);
MAKE_MATRIX_COMMON_TYPEDEFS(EiVDynamic,          2, X, 2);
MAKE_MATRIX_COMMON_TYPEDEFS(EiVDynamic,          3, X, 3);
MAKE_MATRIX_COMMON_TYPEDEFS(EiVDynamic,          4, X, 4);
MAKE_MATRIX_COMMON_TYPEDEFS(EiVDynamic, EiVDynamic, X,  );

#undef MAKE_COMMON_TYPEDEFS
#undef MAKE_MATRIX_COMMON_TYPEDEFS
#endif

#ifdef EIGEN_JACOBI_MODULE_H
template<typename Scalar> using EiVJacobiRotation = Eigen::JacobiRotation<Scalar>;
#endif

#ifdef EIGEN_HOUSEHOLDER_MODULE_H
template<typename VectorsType, typename CoeffsType, int Side> using EiVHouseholderSequence = Eigen::HouseholderSequence<VectorsType, CoeffsType, Side>;
#endif

#ifdef EIGEN_CHOLESKY_MODULE_H
template<typename MatrixType, int UpLo = 1> using EiVLDLT = Eigen::LDLT<MatrixType, UpLo>;
template<typename MatrixType, int UpLo = 1> using EiVLLT  = Eigen::LLT<MatrixType, UpLo>;
#endif

#ifdef EIGEN_LU_MODULE_H
template<typename MatrixType> using EiVFullPivLU    = Eigen::FullPivLU<MatrixType>;
template<typename MatrixType> using EiVPartialPivLU = Eigen::PartialPivLU<MatrixType>;
#endif

#ifdef EIGEN_QR_MODULE_H
template<typename MatrixType> using EiVColPivHouseholderQR              = Eigen::ColPivHouseholderQR<MatrixType>;
template<typename MatrixType> using EiVCompleteOrthhogonalDecomposition = Eigen::CompleteOrthogonalDecomposition<MatrixType>;
template<typename MatrixType> using EiVFullPivHouseholderQR             = Eigen::FullPivHouseholderQR<MatrixType>;
template<typename MatrixType> using EiVHouseholderQR                    = Eigen::HouseholderQR<MatrixType>;
#endif

#ifdef EIGEN_SVD_MODULE_H
template<typename MatrixType>              using EiVBDCSVD    = Eigen::BDCSVD<MatrixType>;
template<typename MatrixType, int Options> using EiVJacobiSVD = Eigen::JacobiSVD<MatrixType,Options>;
template<typename Derived>                 using EiVSVDBase   = Eigen::SVDBase<Derived>;
#endif

#ifdef EIGEN_EIGENVALUES_MODULE_H
template<typename MatrixType> using EiVComplexEigenSolver                = Eigen::ComplexEigenSolver<MatrixType>;
template<typename MatrixType> using EiVComplexSchur                      = Eigen::ComplexSchur<MatrixType>;
template<typename MatrixType> using EiVEigenSolver                       = Eigen::EigenSolver<MatrixType>;
template<typename MatrixType> using EiVGeneralizedEigenSolver            = Eigen::GeneralizedEigenSolver<MatrixType>;
template<typename MatrixType> using EiVGeneralizedSelfAdjointEigenSolver = Eigen::GeneralizedSelfAdjointEigenSolver<MatrixType>;
template<typename MatrixType> using EiVHessenbergDecomposition           = Eigen::HessenbergDecomposition<MatrixType>;
template<typename MatrixType> using EiVRealQZ                            = Eigen::RealQZ<MatrixType>;
template<typename MatrixType> using EiVRealSchur                         = Eigen::RealSchur<MatrixType>;
template<typename MatrixType> using EiVSelfAdjointEigenSolver            = Eigen::SelfAdjointEigenSolver<MatrixType>;
template<typename MatrixType> using EiVTridiagonalization                = Eigen::Tridiagonalization<MatrixType>;
#endif

#ifdef EIGEN_SPARSECORE_MODULE_H
template<typename Derived, int Level = Eigen::internal::accessors_level<Derived>::has_write_access ? Eigen::WriteAccessors : Eigen::ReadOnlyAccessors> using EiVSparseMapBase = Eigen::SparseMapBase<Derived, Level>;
template<typename Scalar, int Options = 0, typename StorageIndex = int>                               using EiVSparseMatrix = Eigen::SparseMatrix<Scalar, Options, StorageIndex>;
template<typename Scalar, int Options = 0, typename StorageIndex = int>                               using EiVSparseVector = Eigen::SparseVector<Scalar, Options, StorageIndex>;
template<typename Scalar, typename StorageIndex = typename Eigen::SparseMatrix<Scalar>::StorageIndex> using EiVTriplet = Eigen::Triplet<Scalar, StorageIndex>;
template<typename Derived>                 using EiVSparseCompressedBase   = Eigen::SparseCompressedBase<Derived>;
template<typename MatrixType, uint32 Mode> using EiVSparseSelfAdjointView  = Eigen::SparseSelfAdjointView<MatrixType, Mode>;
template<typename MatrixType>              using EiVSparseView             = Eigen::SparseView<MatrixType>;
template<typename Derived>                 using EiVSparseMatrixBase       = Eigen::SparseMatrixBase<Derived>;
template<typename Derived>                 using EiVSparseSolverBase       = Eigen::SparseSolverBase<Derived>;
template<typename Derived>                 using EiVSparseMapBaseReadOnly  = Eigen::SparseMapBase<Derived, 0>;
template<typename Derived>                 using EiVSparseMapBaseReadWrite = Eigen::SparseMapBase<Derived, 1>;
#endif

#ifdef EIGEN_ORDERINGMETHODS_MODULE_H
template<typename StorageIndex> using EiVAMDOrdering     = Eigen::AMDOrdering<StorageIndex>;
template<typename StorageIndex> using EiVCOLAMDOrdering  = Eigen::COLAMDOrdering<StorageIndex>;
template<typename StorageIndex> using EiVNatrualOrdering = Eigen::NaturalOrdering<StorageIndex>;
#endif

#ifdef EIGEN_SPARSECHOLESKY_MODULE_H
template<typename MatrixType, int UpLo = 1, typename Ordering = Eigen::AMDOrdering<typename MatrixType::StorageIndex>> using EiVSimplicialCholesky     = Eigen::SimplicialCholesky<MatrixType, UpLo, Ordering>;
template<typename MatrixType, int UpLo = 1, typename Ordering = Eigen::AMDOrdering<typename MatrixType::StorageIndex>> using EiVSimplicialLDLT         = Eigen::SimplicialLDLT<MatrixType, UpLo, Ordering>;
template<typename MatrixType, int UpLo = 1, typename Ordering = Eigen::AMDOrdering<typename MatrixType::StorageIndex>> using EiVSimplicialLLT          = Eigen::SimplicialLLT<MatrixType, UpLo, Ordering>;
template<typename Derived>                                                                                             using EiVSimplicialCholeskyBase = Eigen::SimplicialCholeskyBase<Derived>;
typedef Eigen::SimplicialCholeskyMode EiVSimplicialCholeskyMode;
#endif

#ifdef EIGEN_SPARSELU_MODULE_H
template<typename MatrixType, typename OrderingType = Eigen::COLAMDOrdering<typename MatrixType::StorageIndex>> using EiVSparseLU = Eigen::SparseLU<MatrixType, OrderingType>;
#endif

#ifdef EIGEN_SPARSEQR_MODULE_H
template<typename MatrixType, typename OrderingType> using EiVSparseQR = Eigen::SparseQR<MatrixType, OrderingType>;
#endif

#ifdef EIGEN_ITERATIVELINEARSOLVERS_MODULE_H
template<typename MatrixType, typename Preconditioner = Eigen::DiagonalPreconditioner<typename MatrixType::Scalar>>               using EiVBiCGSTAB                      = Eigen::BiCGSTAB<MatrixType, Preconditioner>;
template<typename MatrixType, int UpLo = 1, typename Preconditioner = Eigen::DiagonalPreconditioner<typename MatrixType::Scalar>> using EiVConjugateGradient             = Eigen::ConjugateGradient<MatrixType, UpLo, Preconditioner>;
template<typename MatrixType, typename Preconditioner = Eigen::LeastSquareDiagonalPreconditioner<typename MatrixType::Scalar>>    using EiVLeastSquaresConjugateGradient = Eigen::LeastSquaresConjugateGradient<MatrixType, Preconditioner>;
template<typename Scalar>                                              using EiVDiagonalPreconditioner            = Eigen::DiagonalPreconditioner<Scalar>;
template<typename Scalar, typename StorageIndex = int>                 using EiVIncompleteLUT                     = Eigen::IncompleteLUT<Scalar, StorageIndex>;
template<typename Scalar>                                              using EiVLeastSquareDiagonalPreconditioner = Eigen::LeastSquareDiagonalPreconditioner<Scalar>;
template<typename Decomposition, typename RhsType, typename GuessType> using EiVSolveWithGuess                    = Eigen::SolveWithGuess<Decomposition,RhsType,GuessType>;
template<typename Derived>                                             using EiVIterativeSolverBase               = Eigen::IterativeSolverBase<Derived>;
typedef Eigen::IdentityPreconditioner EiVIdentityPreconditioner;
#endif

#ifdef EIGEN_GEOMETRY_MODULE_H

// === Classes

template<typename Scalar, int AmbientDim>                     using EiVAlignedBox        = Eigen::AlignedBox<Scalar, AmbientDim>;
template<typename MatrixType, int Direction>                  using EiVHomogeneous       = Eigen::Homogeneous<MatrixType, Direction>;
template<typename Scalar, int AmbientDim, int Options = 0>    using EiVHyperplane        = Eigen::Hyperplane<Scalar, AmbientDim, Options>;
template<typename Scalar, int AmbientDim, int Options = 0>    using EiVParameterizedLine = Eigen::ParametrizedLine<Scalar, AmbientDim, Options>;
template<typename Scalar, int Options = 0>                    using EiVQuaternion        = Eigen::Quaternion<Scalar, Options>;
template<typename Scalar, int Dim, int Mode, int Options = 0> using EiVTransform         = Eigen::Transform<Scalar, Dim, Mode, Options>;
template<typename Scalar, int Dim> using EiVTranslation    = Eigen::Translation<Scalar, Dim>;
template<class Derived>            using EiVQuaternionBase = Eigen::QuaternionBase<Derived>;
template<typename Scalar>          using EiVUniformScaling = Eigen::UniformScaling<Scalar>;
template<typename Scalar>          using EiVAngleAxis      = Eigen::AngleAxis<Scalar>;
template<typename Scalar>          using EiVRotation2D     = Eigen::Rotation2D<Scalar>;

// === Concise Typedefs

#define MAKE_AAB_TYPEDEF_SET(Dim)                        \
typedef Eigen::AlignedBox##Dim##d EiVAlignedBox##Dim##d; \
typedef Eigen::AlignedBox##Dim##f EiVAlignedBox##Dim##f; \
typedef Eigen::AlignedBox##Dim##i EiVAlignedBox##Dim##i; \

typedef Eigen::AngleAxisd            EiVAngleAxisd;
typedef Eigen::AngleAxisf            EiVAngleAxisf;
typedef Eigen::Quaterniond           EiVQuaterniond;
typedef Eigen::Quaternionf           EiVQuaternionf;
typedef Eigen::QuaternionMapd        EiVQuaternionMapd;
typedef Eigen::QuaternionMapf        EiVQuaternionMapf;
typedef Eigen::QuaternionMapAlignedd EiVQuaternionMapAlignedd;
typedef Eigen::QuaternionMapAlignedf EiVQuaternionMapAlignedf;
typedef Eigen::Rotation2Dd           EiVRotation2Dd;
typedef Eigen::Rotation2Df           EiVRotation2Df;
typedef Eigen::Translation2d         EiVTranslation2d;
typedef Eigen::Translation2f         EiVTranslation2f;
typedef Eigen::Translation3d         EiVTranslation3d;
typedef Eigen::Translation3f         EiVTranslation3f;
typedef Eigen::Affine2d              EiVAffine2d;
typedef Eigen::Affine2f              EiVAffine2f;
typedef Eigen::Affine3d              EiVAffine3d;
typedef Eigen::Affine3f              EiVAffine3f;
typedef Eigen::AffineCompact2d       EiVAffineCompact2d;
typedef Eigen::AffineCompact2f       EiVAffineCompact2f;
typedef Eigen::AffineCompact3d       EiVAffineCompact3d;
typedef Eigen::AffineCompact3f       EiVAffineCompact3f;
typedef Eigen::Isometry2d            EiVIsometry2d;
typedef Eigen::Isometry2f            EiVIsometry2f;
typedef Eigen::Isometry3d            EiVIsometry3d;
typedef Eigen::Isometry3f            EiVIsometry3f;
MAKE_AAB_TYPEDEF_SET(1);
MAKE_AAB_TYPEDEF_SET(2);
MAKE_AAB_TYPEDEF_SET(3);
MAKE_AAB_TYPEDEF_SET(4);
MAKE_AAB_TYPEDEF_SET(X);
#endif

#endif // EIV_NO_UTILITY

/**
 * This library contains helper functions for using Unreal types with Eigen and EiV
 */
class EIV_API EiVLibrary
{
	// ...
};
/*
* This is the main struct containing helper functions to work with Unreal types in Eigen and vice versa.
* For most conversion functions, you can also easily convert types to Eigen types with the Eigen Map type.
* This type allows for easy conversion assuming the type being mapped to Eigen has contiguously aligned 
* memory and is of the correct type for the conversion operation (ex. UObject[] will NOT map to Eigen::MatrixXi).
* For this whole struct the <NumericType> is the datatype of the numbers stored in the Eigen types, for input and
* output.
*/
USTRUCT()
struct EIV_API FEiVHelper
{
	// having the direct c++ here allows for local header use of the include macros
	// (if the c++ was in its own file the include macros must be global and then you
	// could no longer have the modular includes on the user end without some jank)

	GENERATED_BODY()
public:
#if !defined(EIV_NO_UTILITY) && defined(EIGEN_CORE_H) //general utility functions
	// This sets the number of threads Eigen can use at any given time
	//@param Threads - the new number of threads that Eigen can use
	static void SetEigenThreads(const int32 Threads)
	{
		const int32 CurrentThreads = Eigen::nbThreads();
		if (Threads != CurrentThreads) {
			Eigen::setNbThreads(Threads);
		}
	}
	// This gets the number of threads Eigen can currently use
	// @returns the number of threads Eigen can use
	static inline int32 GetEigenThreads() { return Eigen::nbThreads(); }
	// Converts a FVector2D to a c++ complex number type for use in Eigen
	// @param InVector - the vector input
	// @param AsPhasor - if this is true the complex number created is formed from the angle from the real axis and the magnitude
	// of the complex number stored in the vector
	// @returns - the complex number version of the input vector
	template<typename NumericType = double>
	static std::complex<NumericType> Vector2DToComplex(const FVector2D& InVector, bool AsPhasor)
	{
		std::complex<NumericType> im;
		if (AsPhasor) {
			im = std::polar<NumericType>(InVector.X, InVector.Y);
		}
		else {
			im = std::complex<NumericType>(InVector.X, InVector.Y);
		}
		return im;
	}
	// Converts to a FVector2D from a c++ complex number type
	// @param InComplex - the complex number input
	// @param AsPhasor - if this is true the vector returned contains the angle from the real axis and the magnitude
	// of the complex number
	// @returns - the FVector2D version of this complex number
	template<typename NumericType = double>
	static FVector2D ComplexToVector2D(const std::complex<NumericType>& InComplex, bool AsPhasor)
	{
		FVector2D Vec;
		if (AsPhasor) {
			Vec.X = std::abs<NumericType>(InComplex);
			Vec.Y = std::arg<NumericType>(InComplex);
		}
		else {
			Vec.X = InComplex.real();
			Vec.Y = InComplex.imag();
		}
		return Vec;
	}
#endif

#if defined(EIGEN_CORE_H) && !defined(EIV_NO_UTILITY) //core functions
#ifdef EIGEN_RUNTIME_NO_MALLOC 
	// This allows Eigen to dynamically allocate memory at runtime
	static inline void AllowEigenMalloc() { Eigen::set_is_malloc_allowed(true); }
	// This prevents Eigen from dynamically allocate memory at runtime
	static inline void DisallowEigenMalloc() { Eigen::set_is_malloc_allowed(false); }
#endif
	// This function creates a null matrix (a matrix of size (0,0))
	// @returns - the null matrix 
	template<typename NumericType = double>
	inline static EiVMatrix<NumericType,0,0> NullMatrix() { return EiVMatrix<NumericType, 0, 0>(); }
	// This function converts an Unreal Engine TArray to an Eigen array
	// @param InArray - the input array
	// @returns - the Eigen version of this array
	template<typename NumericType = double,int Length>
	static EiVArray<NumericType,1, Length> TArrayToArray(const TArray<NumericType>& InArray)
	{
		EiVArray<NumericType, 1, Length> Arr(InArray.Num());
		for (int i = 0; i < InArray.Num() && i < Length; i++) {
			Arr.coeffRef(i) = InArray[i];
		}
		return Arr;
	}
	// This function converts an Unreal Engine TArray to an Eigen array of dynamic length.
	// This is useful if you may not know the size of your input array at the time of this functions execution.
	// @param InArray - the input array
	// @returns - the Eigen version of this array
	template<typename NumericType = double>
	static EiVArray<NumericType, 1, EiVDynamic> TArrayToDynamicArray(const TArray<NumericType>& InArray)
	{
		EiVArray<NumericType, 1, EiVDynamic> Arr(InArray.Num());
		for (int i = 0; i < InArray.Num(); i++) {
			Arr.coeffRef(i) = InArray[i];
		}
		return Arr;
	}
	// This function gets an Unreal Engine TArray from an Eigen array
	// @param InArray - the input array
	// @returns - the Unreal Engine version of this array
	template<typename NumericType = double, int Length>
	static TArray<NumericType> TArrayFromArray(const EiVArray<NumericType, 1, Length>& InArray)
	{
		TArray<NumericType> Arr = TArray<NumericType>();
		for (int i = 0; i < InArray.cols(); i++) {
			Arr.Add(InArray.coeff(i));
		}
		return Arr;
	}
	// This function gets an Unreal Engine TArray from a dynamically sized Eigen array
	// @param InArray - the input array
	// @returns - the Unreal Engine version of this array
	template<typename NumericType = double>
	static TArray<NumericType> TArrayFromDynamicArray(const EiVArray<NumericType, 1, EiVDynamic>& InArray)
	{
		TArray<NumericType> Arr = TArray<NumericType>();
		for (int i = 0; i < InArray.cols(); i++) {
			Arr.Add(InArray.coeff(i));
		}
		return Arr;
	}
	// This function converts an Unreal Engine 2D TArray to an Eigen 2D array
	// @param InArray - the input array
	// @returns - the Eigen version of this 2D array
	template<typename NumericType = double, int Length>
	static EiVArray<NumericType, 2, Length> TArray2DToArray(const TArray<TArray<NumericType>>& InArray)
	{
		EiVArray<NumericType, 2, Length> Arr(2, InArray.Num());
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < InArray.Num() && i < Length; j++) {
				Arr.coeffRef(i, j) = InArray[i][j];
			}
		}
		return Arr;
	}
	// This function gets an Unreal Engine 2D TArray from an Eigen 2D array
	// @param InArray - the input array
	// @returns - the Unreal Engine version of this 2D array
	template<typename NumericType = double, int Length>
	static TArray<TArray<NumericType>> TArray2DFromArray(const EiVArray<NumericType, 2, Length>& InArray)
	{
		TArray<TArray<NumericType>> Arr = TArray<TArray<NumericType>>();
		for (int i = 0; i < InArray.rows(); i++) {
			Arr.Add(TArray<NumericType>());
			for (int j = 0; j < InArray.cols(); j++) {
				Arr[i].Add(InArray.coeffRef(i, j));
			}
		}
		return Arr;
	}
	// This function converts an Unreal Engine FVector2D into an Eigen 2d vector
	// @param InVector - the vector to convert
	// @returns - the Eigen version of this vector
	template<typename NumericType = double>
	static EiVVector2<NumericType> FVectorToVector(const FVector2D& InVector)
	{
		EiVVector2<NumericType> Vec(InVector.X, InVector.Y);
		return Vec;
	}
	// This function gets an Unreal Engine FVector2D from an Eigen 2d vector
	// @param InVector - the vector to convert
	// @returns - the Unreal Engine version of this vector
	template<typename NumericType = double>
	inline static FVector2D FVectorFromVector(const EiVVector2<NumericType>& InVector) { return FVector2D(InVector.coeff(0), InVector.coeff(1)); }
	// This function converts an Unreal Engine FVector into an Eigen vector
	// @param InVector - the vector to convert
	// @returns - the Eigen version of this vector
	template<typename NumericType = double>
	static EiVVector3<NumericType> FVectorToVector(const FVector& InVector)
	{
		EiVVector3<NumericType> Vec(InVector.X, InVector.Y, InVector.Z);
		return Vec;
	}
	// This function gets an Unreal Engine FVector from an Eigen vector
	// @param InVector - the vector to convert
	// @returns - the Unreal Engine version of this vector
	template<typename NumericType = double>
	inline static FVector FVectorFromVector(const EiVVector3<NumericType>& InVector) { return FVector(InVector.coeff(0), InVector.coeff(1), InVector.coeff(2)); }
	// This function converts an Unreal Engine FVector4 into an Eigen 4d vector
	// @param InVector - the vector to convert
	// @returns - the Eigen version of this vector
	template<typename NumericType = double>
	static EiVVector4<NumericType> FVectorToVector(const FVector4& InVector)
	{
		EiVVector4<NumericType> Vec(InVector.X, InVector.Y, InVector.Z, InVector.W);
		return Vec;
	}
	// This function gets an Unreal Engine FVector4 from an Eigen 4d vector
	// @param InVector - the vector to convert
	// @returns - the Unreal Engine version of this vector
	template<typename NumericType = double>
	inline static FVector4 FVectorFromVector(const EiVVector4<NumericType>& InVector) { return FVector4(InVector.coeff(0), InVector.coeff(1), InVector.coeff(2), InVector.coeff(3)); }
	// This function converts an Unreal Engine FVector2D into an Eigen 2d row vector
	// @param InVector - the vector to convert
	// @returns - the Eigen version of this vector
	template<typename NumericType = double>
	static EiVRowVector2<NumericType> FVectorToRowVector(const FVector2D& InVector)
	{
		EiVRowVector2<NumericType> Vec(InVector.X, InVector.Y);
		return Vec;
	}
	// This function gets an Unreal Engine FVector2D from an Eigen 2d row vector
	// @param InVector - the vector to convert
	// @returns - the Unreal Engine version of this vector
	template<typename NumericType = double>
	inline static FVector2D FVectorFromRowVector(const EiVRowVector2<NumericType>& InVector) { return FVector2D(InVector.coeff(0), InVector.coeff(1)); }
	// This function converts an Unreal Engine FVector into an Eigen row vector
	// @param InVector - the vector to convert
	// @returns - the Eigen version of this vector
	template<typename NumericType = double>
	static EiVRowVector3<NumericType> FVectorToRowVector(const FVector& InVector)
	{
		EiVVector3<NumericType> Vec(InVector.X, InVector.Y, InVector.Z);
		return Vec;
	}
	// This function gets an Unreal Engine FVector from an Eigen row vector
	// @param InVector - the vector to convert
	// @returns - the Unreal Engine version of this vector
	template<typename NumericType = double>
	inline static FVector FVectorFromRowVector(const EiVRowVector3<NumericType>& InVector) { return FVector(InVector.coeff(0), InVector.coeff(1), InVector.coeff(2)); }
	// This function converts an Unreal Engine FVector4 into an Eigen 4d row vector
	// @param InVector - the vector to convert
	// @returns - the Eigen version of this vector
	template<typename NumericType = double>
	static EiVRowVector4<NumericType> FVectorToRowVector(const FVector4& InVector)
	{
		EiVVector4<NumericType> Vec(InVector.X, InVector.Y, InVector.Z, InVector.W);
		return Vec;
	}
	// This function gets an Unreal Engine FVector4 from an Eigen 4d row vector
	// @param InVector - the vector to convert
	// @returns - the Unreal Engine version of this vector
	template<typename NumericType = double>
	inline static FVector4 FVectorFromRowVector(const EiVRowVector4<NumericType>& InVector) { return FVector4(InVector.coeff(0), InVector.coeff(1), InVector.coeff(2), InVector.coeff(3)); }
	// This function converts from an Unreal Engine FMatrix to an Eigen Matrix
	// @param InMatrix - the matrix to convert
	// @returns - the Eigen version of this matrix
	template<typename NumericType = double>
	static EiVMatrix<NumericType,4,4> FMatrixToMatrix(const FMatrix& InMatrix)
	{
		EiVMatrix<NumericType, 4, 4> Mtx = EiVMatrix<NumericType, 4, 4>();
		Mtx.coeffRef(0, 0) = InMatrix.M[0][0]; Mtx.coeffRef(0, 1) = InMatrix.M[0][1];
		Mtx.coeffRef(0, 2) = InMatrix.M[0][2]; Mtx.coeffRef(0, 3) = InMatrix.M[0][3];
		Mtx.coeffRef(1, 0) = InMatrix.M[1][0]; Mtx.coeffRef(1, 1) = InMatrix.M[1][1];
		Mtx.coeffRef(1, 2) = InMatrix.M[1][2]; Mtx.coeffRef(1, 3) = InMatrix.M[1][3];
		Mtx.coeffRef(2, 0) = InMatrix.M[2][0]; Mtx.coeffRef(2, 1) = InMatrix.M[2][1];
		Mtx.coeffRef(2, 2) = InMatrix.M[2][2]; Mtx.coeffRef(2, 3) = InMatrix.M[2][3];
		Mtx.coeffRef(3, 0) = InMatrix.M[3][0]; Mtx.coeffRef(3, 1) = InMatrix.M[3][1];
		Mtx.coeffRef(3, 2) = InMatrix.M[3][2]; Mtx.coeffRef(3, 3) = InMatrix.M[3][3];
		return Mtx;
	}
	// This function converts to an Unreal Engine FMatrix from an Eigen Matrix
	// @param InMatrix - the matrix to convert
	// @returns - the Unreal Engine version of this matrix
	template<typename NumericType = double>
	static FMatrix FMatrixFromMatrix(const EiVMatrix<NumericType, 4, 4>& InMatrix)
	{
		FMatrix Mtx = FMatrix();
		Mtx.M[0][0] = InMatrix.coeff(0, 0); Mtx.M[0][1] = InMatrix.coeff(0, 1);
		Mtx.M[0][2] = InMatrix.coeff(0, 2); Mtx.M[0][3] = InMatrix.coeff(0, 3);
		Mtx.M[1][0] = InMatrix.coeff(1, 0); Mtx.M[1][1] = InMatrix.coeff(1, 1);
		Mtx.M[1][2] = InMatrix.coeff(1, 2); Mtx.M[1][3] = InMatrix.coeff(1, 3);
		Mtx.M[2][0] = InMatrix.coeff(2, 0); Mtx.M[2][1] = InMatrix.coeff(2, 1);
		Mtx.M[2][2] = InMatrix.coeff(2, 2); Mtx.M[2][3] = InMatrix.coeff(2, 3);
		Mtx.M[3][0] = InMatrix.coeff(3, 0); Mtx.M[3][1] = InMatrix.coeff(3, 1);
		Mtx.M[3][2] = InMatrix.coeff(3, 2); Mtx.M[3][3] = InMatrix.coeff(3, 3);
		return Mtx;
	}
	// This function converts from an Unreal Engine TArray to an Eigen Matrix
	// @param InArray - the array of matrix elements
	// @returns - the Eigen version of this array-matrix
	template<typename NumericType = double, int Rows, int Cols>
	static EiVMatrix<NumericType,Rows,Cols> TArrayToMatrix(const TArray<NumericType>& InArray)
	{
		EiVMatrix<NumericType, Rows, Cols> Mtx = EiVMatrix<NumericType, Rows, Cols>();
		for (int row = 0; row < Rows; row++) {
			for (int col = 0; col < Cols && (col + row * Cols) < InArray.Num(); col++) {
				Mtx.coeffRef(row, col) = InArray[col + row * Cols];
			}
		}
		return Mtx;
	}
	// This function converts to an Unreal Engine TArray from an Eigen Matrix
	// @param InMatrix - the array of matrix elements
	// @returns - the Unreal Engine version of this array-matrix
	template<typename NumericType = double, int Rows, int Cols>
	static TArray<NumericType> TArrayFromMatrix(const EiVMatrix<NumericType, Rows, Cols>& InMatrix)
	{
		TArray<NumericType> Arr = TArray<NumericType>();
		for (int row = 0; row < InMatrix.rows(); row++) {
			for (int col = 0; col < InMatrix.cols(); col++) {
				Arr.Add(InMatrix.coeffRef(row, col));
			}
		}
		return Arr;
	}
#endif

#if defined(EIGEN_JACOBI_MODULE_H) && !defined(EIV_NO_UTILITY) //jacobi functions
	// This function creates an Eigen JacobiRotation from an FVector2D
	// @param InVector - the vector to take rotation values from
	// @returns - the Eigen JacobiRotationfrom this vector's values
	template<typename NumericType = double>
	static EiVJacobiRotation<NumericType> Vector2DToJacobiRotation(const FVector2D& InVector)
	{
		EiVJacobiRotation<NumericType> Rot = EiVJacobiRotation<NumericType>();
		Rot.c() = InVector.X;
		Rot.s() = InVector.Y;
		return Rot;
	}
	// This function converts from an Eigen JacobiRotation to an FVector2D
	// @param InRotation - the rotation to convert to an FVector2D
	// @returns - the Unreal Engine FVector of this JacobiRotation
	template<typename NumericType = double>
	static FVector2D Vector2DFromJacobiRotation(const EiVJacobiRotation<NumericType>& InRotation)
	{
		FVector2D Vec;
		Vec.X = InRotation.c();
		Vec.Y = InRotation.s();
		return Vec;
	}
#endif

#if defined(EIGEN_SPARSECORE_MODULE_H) && !defined(EIV_NO_UTILITY) //sparse core functions
	// This function converts from an Unreal Engine FVector to an Eigen Triplet 
	// @param InVector - the vector to make a triplet from
	// @returns - the Eigen triplet of this vector
	template<typename NumericType = double>
	static EiVTriplet<NumericType> VectorToTriplet(const FVector& InVector)
	{
		EiVTriplet<NumericType> Triplet = EiVTriplet<NumericType>(InVector.X, InVector.Y, InVector.Z);
		return Triplet;
	}
	// This function converts to an Unreal Engine FVector from an Eigen Triplet 
	// @param InTriplet - the triplet to make a vector from
	// @returns - the Unreal Engine vector of this triplet
	template<typename NumericType = double>
	static FVector VectorFromTriplet(const EiVTriplet<NumericType>& InTriplet)
	{
		FVector Vec;
		Vec.X = InTriplet.row();
		Vec.Y = InTriplet.col();
		Vec.Z = InTriplet.value();
		return Vec;
	}
	// This function converts an Unreal Engine FVector4 into an Eigen sparse vector
	// @param InVector - the vector to convert
	// @returns - the sparse Eigen version of this vector
	template<typename NumericType = double>
	static EiVSparseVector<NumericType> VectorToSparseVector(const FVector4& InVector)
	{
		EiVSparseVector<NumericType> SV(4);
		SV.insert(0) = InVector.X;
		SV.insert(1) = InVector.Y;
		SV.insert(2) = InVector.Z;
		SV.insert(3) = InVector.W;
		return SV;
	}
	// This function converts to an Unreal Engine FVector4 from an Eigen sparse vector
	// @param InSVector - the vector to convert
	// @returns - the Unreal Engine version of this sparse vector
	template<typename NumericType = double>
	static FVector4 Vector4FromSparseVector(const EiVSparseVector<NumericType>& InSVector)
	{
		int DataNum = InSVector.size();
		FVector4 Vec;
		Vec.X = 0 < DataNum ? InSVector.coeff(0) : 0;
		Vec.Y = 1 < DataNum ? InSVector.coeff(1) : 0;
		Vec.Z = 2 < DataNum ? InSVector.coeff(2) : 0;
		Vec.W = 3 < DataNum ? InSVector.coeff(3) : 0;
		return Vec;
	}
	// This function converts an Unreal Engine FVector into an Eigen sparse vector
	// @param InVector - the vector to convert
	// @returns - the sparse Eigen version of this vector
	template<typename NumericType = double>
	static EiVSparseVector<NumericType> VectorToSparseVector(const FVector& InVector)
	{
		EiVSparseVector<NumericType> SV(3);
		SV.insert(0) = InVector.X;
		SV.insert(1) = InVector.Y;
		SV.insert(2) = InVector.Z;
		return SV;
	}
	// This function converts to an Unreal Engine FVector from an Eigen sparse vector
	// @param InSVector - the vector to convert
	// @returns - the Unreal Engine version of this sparse vector
	template<typename NumericType = double>
	static FVector VectorFromSparseVector(const EiVSparseVector<NumericType>& InSVector)
	{
		FVector4 Vec = FEiVHelper::Vector4FromSparseVector<NumericType>(InSVector);
		return FVector(Vec.X, Vec.Y, Vec.Z);
	}
	// This function converts an Unreal Engine FVector2D into an Eigen sparse vector
	// @param InVector - the vector to convert
	// @returns - the sparse Eigen version of this vector
	template<typename NumericType = double>
	static EiVSparseVector<NumericType> VectorToSparseVector(const FVector2D& InVector)
	{
		EiVSparseVector<NumericType> SV(2);
		SV.insert(0) = InVector.X;
		SV.insert(1) = InVector.Y;
		return SV;
	}
	// This function converts to an Unreal Engine FVector2D from an Eigen sparse vector
	// @param InSVector - the vector to convert
	// @returns - the Unreal Engine version of this sparse vector
	template<typename NumericType = double>
	static FVector2D Vector2DFromSparseVector(const EiVSparseVector<NumericType>& InSVector)
	{
		FVector4 Vec = FEiVHelper::Vector4FromSparseVector<NumericType>(InSVector);
		return FVector2D(Vec.X, Vec.Y);
	}
	// This function converts from an Unreal Engine FMatrix to an Eigen SparseMatrix
	// @param InMatrix - the matrix to convert
	// @returns - the Eigen version of this matrix
	template<typename NumericType = double>
	static EiVSparseMatrix<NumericType> FMatrixToSparseMatrix(const FMatrix& InMatrix)
	{
		EiVSparseMatrix<NumericType> Mtx(4, 4);
		Mtx.insert(0, 0) = InMatrix.M[0][0]; Mtx.insert(0, 1) = InMatrix.M[0][1];
		Mtx.insert(0, 2) = InMatrix.M[0][2]; Mtx.insert(0, 3) = InMatrix.M[0][3];
		Mtx.insert(1, 0) = InMatrix.M[1][0]; Mtx.insert(1, 1) = InMatrix.M[1][1];
		Mtx.insert(1, 2) = InMatrix.M[1][2]; Mtx.insert(1, 3) = InMatrix.M[1][3];
		Mtx.insert(2, 0) = InMatrix.M[2][0]; Mtx.insert(2, 1) = InMatrix.M[2][1];
		Mtx.insert(2, 2) = InMatrix.M[2][2]; Mtx.insert(2, 3) = InMatrix.M[2][3];
		Mtx.insert(3, 0) = InMatrix.M[3][0]; Mtx.insert(3, 1) = InMatrix.M[3][1];
		Mtx.insert(3, 2) = InMatrix.M[3][2]; Mtx.insert(3, 3) = InMatrix.M[3][3];
		return Mtx;
	}
	// This function converts to an Unreal Engine FMatrix from an Eigen SparseMatrix
	// @param InMatrix - the matrix to convert
	// @returns - the Unreal Engine version of this matrix
	template<typename NumericType = double>
	static FMatrix FMatrixFromSparseMatrix(const EiVSparseMatrix<NumericType>& InMatrix)
	{
		FMatrix Mtx = FMatrix();
		if (InMatrix.rows() == 4 && InMatrix.cols() == 4) {
			Mtx.M[0][0] = InMatrix.coeff(0, 0); Mtx.M[0][1] = InMatrix.coeff(0, 1);
			Mtx.M[0][2] = InMatrix.coeff(0, 2); Mtx.M[0][3] = InMatrix.coeff(0, 3);
			Mtx.M[1][0] = InMatrix.coeff(1, 0); Mtx.M[1][1] = InMatrix.coeff(1, 1);
			Mtx.M[1][2] = InMatrix.coeff(1, 2); Mtx.M[1][3] = InMatrix.coeff(1, 3);
			Mtx.M[2][0] = InMatrix.coeff(2, 0); Mtx.M[2][1] = InMatrix.coeff(2, 1);
			Mtx.M[2][2] = InMatrix.coeff(2, 2); Mtx.M[2][3] = InMatrix.coeff(2, 3);
			Mtx.M[3][0] = InMatrix.coeff(3, 0); Mtx.M[3][1] = InMatrix.coeff(3, 1);
			Mtx.M[3][2] = InMatrix.coeff(3, 2); Mtx.M[3][3] = InMatrix.coeff(3, 3);
		}
		return Mtx;
	}
	// This function converts to an Unreal Engine FMatrix44 from an Eigen SparseMatrix
	// @param InMatrix - the matrix to convert
	// @returns - the Unreal Engine version of this matrix
	template<typename NumericType = double>
	static FMatrix44d FMatrix4x4FromSparseMatrix(const EiVSparseMatrix<NumericType>& InMatrix)
	{
		FMatrix44d Mtx = FMatrix44d();
		if (InMatrix.rows() == 4 && InMatrix.cols() == 4) {
			Mtx.M[0][0] = InMatrix.coeff(0, 0); Mtx.M[0][1] = InMatrix.coeff(0, 1);
			Mtx.M[0][2] = InMatrix.coeff(0, 2); Mtx.M[0][3] = InMatrix.coeff(0, 3);
			Mtx.M[1][0] = InMatrix.coeff(1, 0); Mtx.M[1][1] = InMatrix.coeff(1, 1);
			Mtx.M[1][2] = InMatrix.coeff(1, 2); Mtx.M[1][3] = InMatrix.coeff(1, 3);
			Mtx.M[2][0] = InMatrix.coeff(2, 0); Mtx.M[2][1] = InMatrix.coeff(2, 1);
			Mtx.M[2][2] = InMatrix.coeff(2, 2); Mtx.M[2][3] = InMatrix.coeff(2, 3);
			Mtx.M[3][0] = InMatrix.coeff(3, 0); Mtx.M[3][1] = InMatrix.coeff(3, 1);
			Mtx.M[3][2] = InMatrix.coeff(3, 2); Mtx.M[3][3] = InMatrix.coeff(3, 3);
		}
		return Mtx;
	}
	// This function converts from an Unreal Engine TArray to an Eigen SparseMatrix
	// @param InArray - the array of matrix elements
	// @param Rows - the number of rows to make the matrix with
	// @param Cols - the number of columsn to make the matrix with
	// @returns - the Eigen version of this array-matrix
	template<typename NumericType = double>
	static EiVSparseMatrix<NumericType> TArrayToSparseMatrix(const TArray<NumericType>& InArray, const int32& InRows, const int32& InCols)
	{
		EiVSparseMatrix<NumericType> Mtx(InRows, InCols);
		for (int row = 0; row < InRows; row++) {
			for (int col = 0; col < InCols && (col + row * InCols) < InArray.Num(); col++) {
				Mtx.insert(row, col) = InArray[col + row * InCols];
			}
		}
		return Mtx;
	}
	// This function converts to an Unreal Engine TArray from an Eigen SparseMatrix
	// @param InMatrix - the array of matrix elements
	// @returns - the Unreal Engine version of this array-matrix
	template<typename NumericType = double>
	static TArray<NumericType> TArrayFromSparseMatrix(const EiVSparseMatrix<NumericType>& InMatrix)
	{
		TArray<NumericType> Arr = TArray<NumericType>();
		for (int row = 0; row < InMatrix.rows(); row++) {
			for (int col = 0; col < InMatrix.cols(); col++) {
				Arr.Add(InMatrix.coeff(row, col));
			}
		}
		return Arr;
	}
#endif

#if defined(EIGEN_GEOMETRY_MODULE_H) && !defined(EIV_NO_UTILITY) //geometry functions
	// This function creates an Eigen AngleAxis object from an Unreal Engine FQuat
	// @param InQuat - the quaternion to convert to the AngleAxis
	// @returns the Eigen AngleAxis representation of this quaternion
	template<typename NumericType = double>
	static EiVAngleAxis<NumericType> QuatToAngleAxis(const FQuat& InQuat)
	{
		FVector Axis;
		double Angle;
		InQuat.ToAxisAndAngle(Axis,Angle);
		EiVVector3d VecAxis(Axis.X,Axis.Y,Axis.Z);
		EiVAngleAxis<NumericType> AAxis(Angle,VecAxis);
		return AAxis;
	}
	// This function creates an Eigen AngleAxis object from an Unreal Engine FRotator
	// @param InRotator - the rotator to convert to the AngleAxis
	// @returns the Eigen AngleAxis representation of this rotator
	template<typename NumericType = double>
	static EiVAngleAxis<NumericType> RotatorToAngleAxis(const FRotator& InRotator)
	{
		FQuat Quat = InRotator.Quaternion();
		return FEiVHelper::QuatToAngleAxis(Quat);
	}
	// This function creates an Eigen Quaternion object from an Unreal Engine FQuat
	// @param InQuat - the FQuat to convert to the quaternion
	// @returns the Eigen Quaternion representation of this quaternion
	template<typename NumericType = double>
	static EiVQuaternion<NumericType> QuatToQuaternion(const FQuat& InQuat)
	{
		EiVQuaternion<NumericType> Quat = EiVQuaternion<NumericType>(InQuat.W, InQuat.X, InQuat.Y, InQuat.Z);
		return Quat;
	}
	// This function creates an Eigen Rotation2D object from an Unreal Engine FRotator
	// @param InRotator - the rotator to convert to the Rotation2D
	// @returns the Eigen Rotation2D representation of this rotator
	template<typename NumericType = double>
	static EiVRotation2D<NumericType> RotatorTo2DRotation(const FRotator& InRotator)
	{
		EiVRotation2D<NumericType> Rotation;
		Rotation.angle() = FMath::DegreesToRadians(InRotator.Pitch);
		return Rotation;
	}
	// This function creates an Eigen Translation object from an Unreal Engine FVector2D
	// @param InVector - the vector to make a translation from
	// @returns - the Eigen Translation of this vector
	template<typename NumericType = double>
	static EiVTranslation<NumericType,2> VectorToTranslation(const FVector2D& InVector)
	{
		EiVTranslation<NumericType, 2> Translation;
		Translation.x() = InVector.X;
		Translation.y() = InVector.Y;
		return Translation;
	}
	// This function creates an Eigen Translation object from an Unreal Engine FVector
	// @param InVector - the vector to make a translation from
	// @returns - the Eigen Translation of this vector
	template<typename NumericType = double>
	static EiVTranslation<NumericType,3> VectorToTranslation(const FVector& InVector)
	{
		EiVTranslation<NumericType, 3> Translation;
		Translation.x() = InVector.X;
		Translation.y() = InVector.Y;
		Translation.z() = InVector.Z;
		return Translation;
	}
	// This function creates an Eigen AlignedBox object from an Unreal Engine FBox2D
	// @param InBox - the box to create an axis-aligned box from
	// @returns - the Eigen AlignedBox of this box
	template<typename NumericType = double>
	static EiVAlignedBox<NumericType,2> FBoxToAABox(const FBox2D& InBox)
	{
		FVector2D Min = InBox.Min;
		FVector2D Max = InBox.Max;
		EiVAlignedBox<NumericType, 2> Box = EiVAlignedBox<NumericType, 2>(EiVVector2d(Min.X, Min.Y), EiVVector2d(Max.X, Max.Y));
		return Box;
	}
	// This function creates an Eigen AlignedBox object from an Unreal Engine FBox
	// @param InBox - the box to create an axis-aligned box from
	// @returns - the Eigen AlignedBox of this box
	template<typename NumericType = double>
	static EiVAlignedBox<NumericType,3> FBoxToAABox(const FBox& InBox)
	{
		FVector Min = InBox.Min;
		FVector Max = InBox.Max;
		EiVAlignedBox<NumericType, 3> Box = EiVAlignedBox<NumericType, 3>(EiVVector3d(Min.X, Min.Y, Min.Z), EiVVector3d(Max.X, Max.Y, Max.Z));
		return Box;
	}
	// Constructs an Eigen UnformScaling object from a scalar
	// @param InValue - the value of the uniform scaling
	// @returns - the Eigen uniform scaling object
	template<typename NumericType = double>
	static EiVUniformScaling<NumericType> ScalarToUniformScaling(const NumericType& InValue)
	{
		EiVUniformScaling<NumericType> Scaling = EiVUniformScaling<NumericType>(InValue);
		return Scaling;
	}
	// This function creates an Eigen ParameterizedLine object from an Unreal Engine FVector2D
	// @param InVector - the vector to create the line from
	// @returns - the Eigen ParameterizedLine of this vector
	template<typename NumericType = double>
	static EiVParameterizedLine<NumericType, 2> VectorToParameterizedLine(const FVector2D& InVector)
	{
		FVector2D Vec = InVector;
		Vec.Normalize();
		EiVParameterizedLine<NumericType, 2> Line = EiVParameterizedLine<NumericType, 2>(EiVVector2d(0, 0), EiVVector2d(Vec.X, Vec.Y));
		return Line;
	}
	// This function creates an Eigen ParameterizedLine object from an Unreal Engine FVector
	// @param InVector - the vector to create the line from
	// @returns - the Eigen ParameterizedLine of this vector
	template<typename NumericType = double>
	static EiVParameterizedLine<NumericType, 3> VectorToParameterizedLine(const FVector& InVector)
	{
		FVector Vec = InVector;
		Vec.Normalize();
		EiVParameterizedLine<NumericType, 3> Line = EiVParameterizedLine<NumericType, 3>(EiVVector3d(0, 0, 0), EiVVector3d(Vec.X, Vec.Y, Vec.Z));
		return Line;
	}
	// This function creates an Eigen ParameterizedLine object from an Unreal Engine FRay
	// @param InRay - the ray to create the line from
	// @returns - the Eigen ParameterizedLine of this ray
	template<typename NumericType = double>
	static EiVParameterizedLine<NumericType, 3> RayToParameterizedLine(const FRay& InRay)
	{
		FVector Dir = InRay.Direction;
		FVector Origin = InRay.Origin;
		Dir.Normalize();
		EiVParameterizedLine<NumericType, 3> Line = EiVParameterizedLine<NumericType, 3>(EiVVector3d(Origin.X, Origin.Y, Origin.Z), EiVVector3d(Dir.X, Dir.Y, Dir.Z));
		return Line;
	}
	// This function converts from an Eigen AngleAxis object to an Unreal Engine FQuat
	// @param InAngleAxis - the AngleAxis to convert to the quaternion
	// @returns the FQuat representation of this AngleAxis
	template<typename NumericType = double>
	static FQuat QuatFromAngleAxis(const EiVAngleAxis<NumericType>& InAngleAxis)
	{
		FVector Axis;
		EiVVector3d Vec = InAngleAxis.axis();
		Axis.X = Vec.x();
		Axis.Y = Vec.y();
		Axis.Z = Vec.z();
		Axis.Normalize();
		double Angle = InAngleAxis.angle();
		return FQuat(Axis, Angle);
	}
	// This function converts from an Eigen AngleAxis object to an Unreal Engine FRotator
	// @param InAngleAxis - the AngleAxis to convert to the rotator
	// @returns the FRotator representation of this AngleAxis
	template<typename NumericType = double>
	static FRotator RotatorFromAngleAxis(const EiVAngleAxis<NumericType>& InAngleAxis)
	{
		FQuat Quat = FEiVHelper::QuatFromAngleAxis<NumericType>(InAngleAxis);
		return Quat.Rotator();
	}
	// This function converts an Eigen Quaternion object to an Unreal Engine FQuat
	// @param InQuaternion - the quaternion to convert to the FQuat
	// @returns the FQuat representation of this quaternion
	template<typename NumericType = double>
	static FQuat QuatFromQuaternion(const EiVQuaternion<NumericType>& InQuaternion)
	{
		FQuat Out;
		Out.X = InQuaternion.x();
		Out.Y = InQuaternion.y();
		Out.Z = InQuaternion.z();
		Out.W = InQuaternion.w();
		return Out;
	}
	// This function converts an Eigen Rotation2D object to an Unreal Engine FRotator
	// @param InRotation - the Rotation2D to convert to the rotator
	// @returns the FRotator representation of this rotation
	template<typename NumericType = double>
	static FRotator RotatorFrom2DRotation(const EiVRotation2D<NumericType>& InRotation)
	{
		FRotator Rotator = FRotator(0, 0, 0);
		Rotator.Pitch = FMath::RadiansToDegrees(InRotation.angle());
		return Rotator;
	}
	// This function converts an Eigen Translation object to an Unreal Engine FVector2D
	// @param InTranslation - the translation to make a vector from
	// @returns - the FVector2D of this translation
	template<typename NumericType = double>
	inline static FVector2D VectorFromTranslation(const EiVTranslation<NumericType, 2>& InTranslation) { return FVector2D(InTranslation.x(), InTranslation.y()); }
	// This function converts an Eigen Translation object to an Unreal Engine FVector
	// @param InTranslation - the translation to make a vector from
	// @returns - the FVector of this translation
	template<typename NumericType = double>
	inline static FVector VectorFromTranslation(const EiVTranslation<NumericType, 3>& InTranslation) { return FVector(InTranslation.x(), InTranslation.y(), InTranslation.z()); }
	// This function converts an Eigen AlignedBox object to an Unreal Engine FBox2D
	// @param InAABox - the axis-aligned box to create a box from
	// @returns - the FBox2D of this AlignedBox
	template<typename NumericType = double>
	static FBox2D FBoxFromAABox(const EiVAlignedBox<NumericType, 2>& InAABox)
	{
		EiVVector3d VecMin = InAABox.min();
		EiVVector3d VecMax = InAABox.max();
		FVector2D Min = FVector2D(VecMin.x(), VecMin.y());
		FVector2D Max = FVector2D(VecMax.x(), VecMax.y());
		return FBox2D(Min, Max);
	}
	// This function converts an Eigen AlignedBox object to an Unreal Engine FBox
	// @param InAABox - the axis-aligned box to create a box from
	// @returns - the FBox of this AlignedBox
	template<typename NumericType = double>
	static FBox FBoxFromAABox(const EiVAlignedBox<NumericType, 3>& InAABox)
	{
		EiVVector3d VecMin = InAABox.min();
		EiVVector3d VecMax = InAABox.max();
		FVector Min = FVector(VecMin.x(), VecMin.y(), VecMin.z());
		FVector Max = FVector(VecMax.x(), VecMax.y(), VecMax.z());
		return FBox(Min, Max);
	}
	// Converts an Eigen UnformScaling object to a scalar
	// @param InScaling - the uniform scaling to get the value of
	// @returns - the scalar from the Uniform Scaling
	template<typename NumericType = double>
	static NumericType ScalarFromUniformScaling(const EiVUniformScaling<NumericType>& InScaling)
	{
		NumericType Fac = InScaling.factor();
		return Fac;
	}
	// This function converts from an Eigen ParameterizedLine object to an Unreal Engine FVector2D
	// @param InLine - the line to get the vector from
	// @returns - the vector of this Eigen ParameterizedLine
	template<typename NumericType = double>
	static FVector2D VectorFromParameterizedLine(const EiVParameterizedLine<NumericType, 2>& InLine)
	{
		EiVVector2d Dir = InLine.direction();
		return FVector2D(Dir.x(), Dir.y());
	}
	// This function converts from an Eigen ParameterizedLine object to an Unreal Engine FVector
	// @param InLine - the line to get the vector from
	// @returns - the vector of this Eigen ParameterizedLine
	template<typename NumericType = double>
	static FVector VectorFromParameterizedLine(const EiVParameterizedLine<NumericType, 3>& InLine)
	{
		EiVVector3d Dir = InLine.direction();
		return FVector(Dir.x(), Dir.y(), Dir.z());
	}
	// This function converts from an Eigen ParameterizedLine object to an Unreal Engine FRay
	// @param InLine - the line to get the ray from
	// @returns - the ray of this Eigen ParameterizedLine
	template<typename NumericType = double>
	static FRay RayFromParameterizedLine(const EiVParameterizedLine<NumericType, 3>& InLine)
	{
		EiVVector3d Dir = InLine.direction();
		EiVVector3d Origin = InLine.origin();
		return FRay(FVector(Origin.x(), Origin.y(), Origin.z()), FVector(Dir.x(), Dir.y(), Dir.z()));
	}
#endif

};


// Auto-undefinition of include macros
// Toggle this with the EIV_UNDEFINE_INCLUDES
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_CORE)
#undef EIV_INCLUDE_CORE
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_JACOBI)
#undef EIV_INCLUDE_JACOBI
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_HOUSEHOLDER)
#undef EIV_INCLUDE_HOUSEHOLDER
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_CHOLESKY)
#undef EIV_INCLUDE_CHOLESKY
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_LU)
#undef EIV_INCLUDE_LU
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_QR)
#undef EIV_INCLUDE_QR
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_SVD)
#undef EIV_INCLUDE_SVD
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_EIGENVALUES)
#undef EIV_INCLUDE_EIGENVALUES
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_SPARSECORE)
#undef EIV_INCLUDE_SPARSECORE
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_ORDERINGMETHODS)
#undef EIV_INCLUDE_ORDERINGMETHODS
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_SPARSECHOLESKY)
#undef EIV_INCLUDE_SPARSECHOLESKY
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_SPARSELU)
#undef EIV_INCLUDE_SPARSELU
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_SPARSEQR)
#undef EIV_INCLUDE_SPARSEQR
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_ITERATIVELINEARSOLVERS)
#undef EIV_INCLUDE_ITERATIVELINEARSOLVERS
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_GEOMETRY)
#undef EIV_INCLUDE_GEOMETRY
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_DENSE_MATRIX_ARRAY)
#undef EIV_INCLUDE_DENSE_MATRIX_ARRAY
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_DENSE_LINEAR_PROBLEMS)
#undef EIV_INCLUDE_DENSE_LINEAR_PROBLEMS
#endif
#if defined(EIV_UNDEFINE_INCLUDES) && defined(EIV_INCLUDE_SPARSE_LINEAR_ALGEBRA)
#undef EIV_INCLUDE_SPARSE_LINEAR_ALGEBRA
#endif
#ifdef EIV_NO_UTILITY
#undef EIV_NO_UTILITY
#endif
#ifdef EIV_UNDEFINE_INCLUDES
#undef EIV_UNDEFINE_INCLUDES
#endif

