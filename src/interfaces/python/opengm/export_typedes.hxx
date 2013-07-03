 #ifndef EXPORT_TYPEDES_HXX
#define	EXPORT_TYPEDES_HXX

#include <map>

#include <opengm/graphicalmodel/graphicalmodel.hxx>
#include <opengm/functions/potts.hxx>
#include <opengm/utilities/tribool.hxx>

#include "opengm/utilities/functors.hxx"
#include "opengm/functions/explicit_function.hxx"
#include "opengm/functions/absolute_difference.hxx"
#include "opengm/functions/potts.hxx"
#include "opengm/functions/pottsn.hxx"
#include "opengm/functions/pottsg.hxx"
#include "opengm/functions/squared_difference.hxx"
#include "opengm/functions/truncated_absolute_difference.hxx"
#include "opengm/functions/truncated_squared_difference.hxx"
#include "opengm/functions/sparsemarray.hxx"
#include "opengmcore/pyPythonFunction.hxx"

template<class V,class I,class O,class F>
struct GmGen{
   typedef opengm::DiscreteSpace<I,I> SpaceType;
   typedef opengm::GraphicalModel<V,O,F,SpaceType,false> type;
};
template<class V,class I>
struct ETLGen{
   typedef opengm::ExplicitFunction<V ,I,I> type;
};

template<class V,class I>
struct FTLGen{

   typedef V ValueType;
   typedef I IndexType;
   typedef I LabelType;
   typedef opengm::ExplicitFunction                      <ValueType,IndexType,LabelType> PyExplicitFunction;
   typedef opengm::PottsFunction                         <ValueType,IndexType,LabelType> PyPottsFunction;
   typedef opengm::PottsNFunction                        <ValueType,IndexType,LabelType> PyPottsNFunction;
   typedef opengm::PottsGFunction                        <ValueType,IndexType,LabelType> PyPottsGFunction;
   typedef opengm::TruncatedAbsoluteDifferenceFunction   <ValueType,IndexType,LabelType> PyTruncatedAbsoluteDifferenceFunction;
   typedef opengm::TruncatedSquaredDifferenceFunction    <ValueType,IndexType,LabelType> PyTruncatedSquaredDifferenceFunction;
   typedef opengm::SparseFunction                        <ValueType,IndexType,LabelType> PySparseFunction; 
   typedef PythonFunction                                <ValueType,IndexType,LabelType> PyPythonFunction; 

   typedef typename opengm::meta::TypeListGenerator<
      PyExplicitFunction,
      PyPottsFunction,
      PyPottsNFunction,
      PyPottsGFunction,
      PyTruncatedAbsoluteDifferenceFunction,
      PyTruncatedSquaredDifferenceFunction,
      PySparseFunction,
      PyPythonFunction
   >::type type;
};


typedef double GmValueType;
typedef opengm::UInt64Type GmIndexType;

typedef std::vector<GmIndexType> IndexVectorType;
typedef std::vector<IndexVectorType> IndexVectorVectorType;

typedef GmGen<
   GmValueType,
   GmIndexType,
   opengm::Adder ,
   FTLGen<GmValueType,GmIndexType>::type
>::type   GmAdder;

typedef GmAdder::FactorType FactorGmAdder;

typedef GmGen<
   GmValueType,
   GmIndexType,
   opengm::Multiplier ,
   FTLGen<GmValueType,GmIndexType>::type
>::type   GmMultiplier;

typedef GmMultiplier::FactorType FactorGmMultiplier;

typedef opengm::IndependentFactor<GmValueType,GmIndexType,GmIndexType> GmIndependentFactor;

namespace pyenums{
   enum AStarHeuristic{
      DEFAULT_HEURISTIC=0,
      FAST_HEURISTIC=1,
      STANDARD_HEURISTIC=2
   };
   enum IcmMoveType{
      SINGLE_VARIABLE=0,
      FACTOR=1
   };
   enum GibbsVariableProposal{
      RANDOM=0,
      CYCLIC=1
   };

   enum TrwsEnergyType{
      VIEW=0, TABLES=1, TL1=2, TL2=3
   };
}

#endif	/* EXPORT_TYPEDES_HXX */

