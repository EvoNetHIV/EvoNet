// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// viral_dynamics_aim3
List viral_dynamics_aim3(long Agent, double time_0, double time_final, double h, long Num_Loci, double m, double k, double r_base, double d, double f_M, double f_L, double d_M, double d_L, double p, double p_M, double p_L, double M_act, double L_act, double V0, double V_peak, double t_peak, double t_acute, double V_AIDS, double mu, DataFrame cost_DT, int additive_fitness, DataFrame Drug_DT, double SPVL, double prog_rate, double vl_increase_AIDS, double Time_Inf, long Immune_Response_Triggered, long ChronicPhaseBegins, long TherapyStarted, long SecondLineTherapyStarted, double Adherence1, double Adherence2, double Adherence3, double Adherence4, DataFrame Virus_DT, int Interaction_Model_Drugs12, DataFrame FC_DT, double StochasticCut, double cut, double K, double c, double CD4, double Drug1, double Drug2, double Drug3, double Drug4, int Dosing_Interval, int Therapy_Type, DataFrame stop_restart_DT, long Aim3RoundingErrors);
RcppExport SEXP _evonet_viral_dynamics_aim3(SEXP AgentSEXP, SEXP time_0SEXP, SEXP time_finalSEXP, SEXP hSEXP, SEXP Num_LociSEXP, SEXP mSEXP, SEXP kSEXP, SEXP r_baseSEXP, SEXP dSEXP, SEXP f_MSEXP, SEXP f_LSEXP, SEXP d_MSEXP, SEXP d_LSEXP, SEXP pSEXP, SEXP p_MSEXP, SEXP p_LSEXP, SEXP M_actSEXP, SEXP L_actSEXP, SEXP V0SEXP, SEXP V_peakSEXP, SEXP t_peakSEXP, SEXP t_acuteSEXP, SEXP V_AIDSSEXP, SEXP muSEXP, SEXP cost_DTSEXP, SEXP additive_fitnessSEXP, SEXP Drug_DTSEXP, SEXP SPVLSEXP, SEXP prog_rateSEXP, SEXP vl_increase_AIDSSEXP, SEXP Time_InfSEXP, SEXP Immune_Response_TriggeredSEXP, SEXP ChronicPhaseBeginsSEXP, SEXP TherapyStartedSEXP, SEXP SecondLineTherapyStartedSEXP, SEXP Adherence1SEXP, SEXP Adherence2SEXP, SEXP Adherence3SEXP, SEXP Adherence4SEXP, SEXP Virus_DTSEXP, SEXP Interaction_Model_Drugs12SEXP, SEXP FC_DTSEXP, SEXP StochasticCutSEXP, SEXP cutSEXP, SEXP KSEXP, SEXP cSEXP, SEXP CD4SEXP, SEXP Drug1SEXP, SEXP Drug2SEXP, SEXP Drug3SEXP, SEXP Drug4SEXP, SEXP Dosing_IntervalSEXP, SEXP Therapy_TypeSEXP, SEXP stop_restart_DTSEXP, SEXP Aim3RoundingErrorsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< long >::type Agent(AgentSEXP);
    Rcpp::traits::input_parameter< double >::type time_0(time_0SEXP);
    Rcpp::traits::input_parameter< double >::type time_final(time_finalSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< long >::type Num_Loci(Num_LociSEXP);
    Rcpp::traits::input_parameter< double >::type m(mSEXP);
    Rcpp::traits::input_parameter< double >::type k(kSEXP);
    Rcpp::traits::input_parameter< double >::type r_base(r_baseSEXP);
    Rcpp::traits::input_parameter< double >::type d(dSEXP);
    Rcpp::traits::input_parameter< double >::type f_M(f_MSEXP);
    Rcpp::traits::input_parameter< double >::type f_L(f_LSEXP);
    Rcpp::traits::input_parameter< double >::type d_M(d_MSEXP);
    Rcpp::traits::input_parameter< double >::type d_L(d_LSEXP);
    Rcpp::traits::input_parameter< double >::type p(pSEXP);
    Rcpp::traits::input_parameter< double >::type p_M(p_MSEXP);
    Rcpp::traits::input_parameter< double >::type p_L(p_LSEXP);
    Rcpp::traits::input_parameter< double >::type M_act(M_actSEXP);
    Rcpp::traits::input_parameter< double >::type L_act(L_actSEXP);
    Rcpp::traits::input_parameter< double >::type V0(V0SEXP);
    Rcpp::traits::input_parameter< double >::type V_peak(V_peakSEXP);
    Rcpp::traits::input_parameter< double >::type t_peak(t_peakSEXP);
    Rcpp::traits::input_parameter< double >::type t_acute(t_acuteSEXP);
    Rcpp::traits::input_parameter< double >::type V_AIDS(V_AIDSSEXP);
    Rcpp::traits::input_parameter< double >::type mu(muSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type cost_DT(cost_DTSEXP);
    Rcpp::traits::input_parameter< int >::type additive_fitness(additive_fitnessSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type Drug_DT(Drug_DTSEXP);
    Rcpp::traits::input_parameter< double >::type SPVL(SPVLSEXP);
    Rcpp::traits::input_parameter< double >::type prog_rate(prog_rateSEXP);
    Rcpp::traits::input_parameter< double >::type vl_increase_AIDS(vl_increase_AIDSSEXP);
    Rcpp::traits::input_parameter< double >::type Time_Inf(Time_InfSEXP);
    Rcpp::traits::input_parameter< long >::type Immune_Response_Triggered(Immune_Response_TriggeredSEXP);
    Rcpp::traits::input_parameter< long >::type ChronicPhaseBegins(ChronicPhaseBeginsSEXP);
    Rcpp::traits::input_parameter< long >::type TherapyStarted(TherapyStartedSEXP);
    Rcpp::traits::input_parameter< long >::type SecondLineTherapyStarted(SecondLineTherapyStartedSEXP);
    Rcpp::traits::input_parameter< double >::type Adherence1(Adherence1SEXP);
    Rcpp::traits::input_parameter< double >::type Adherence2(Adherence2SEXP);
    Rcpp::traits::input_parameter< double >::type Adherence3(Adherence3SEXP);
    Rcpp::traits::input_parameter< double >::type Adherence4(Adherence4SEXP);
    Rcpp::traits::input_parameter< DataFrame >::type Virus_DT(Virus_DTSEXP);
    Rcpp::traits::input_parameter< int >::type Interaction_Model_Drugs12(Interaction_Model_Drugs12SEXP);
    Rcpp::traits::input_parameter< DataFrame >::type FC_DT(FC_DTSEXP);
    Rcpp::traits::input_parameter< double >::type StochasticCut(StochasticCutSEXP);
    Rcpp::traits::input_parameter< double >::type cut(cutSEXP);
    Rcpp::traits::input_parameter< double >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type c(cSEXP);
    Rcpp::traits::input_parameter< double >::type CD4(CD4SEXP);
    Rcpp::traits::input_parameter< double >::type Drug1(Drug1SEXP);
    Rcpp::traits::input_parameter< double >::type Drug2(Drug2SEXP);
    Rcpp::traits::input_parameter< double >::type Drug3(Drug3SEXP);
    Rcpp::traits::input_parameter< double >::type Drug4(Drug4SEXP);
    Rcpp::traits::input_parameter< int >::type Dosing_Interval(Dosing_IntervalSEXP);
    Rcpp::traits::input_parameter< int >::type Therapy_Type(Therapy_TypeSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type stop_restart_DT(stop_restart_DTSEXP);
    Rcpp::traits::input_parameter< long >::type Aim3RoundingErrors(Aim3RoundingErrorsSEXP);
    rcpp_result_gen = Rcpp::wrap(viral_dynamics_aim3(Agent, time_0, time_final, h, Num_Loci, m, k, r_base, d, f_M, f_L, d_M, d_L, p, p_M, p_L, M_act, L_act, V0, V_peak, t_peak, t_acute, V_AIDS, mu, cost_DT, additive_fitness, Drug_DT, SPVL, prog_rate, vl_increase_AIDS, Time_Inf, Immune_Response_Triggered, ChronicPhaseBegins, TherapyStarted, SecondLineTherapyStarted, Adherence1, Adherence2, Adherence3, Adherence4, Virus_DT, Interaction_Model_Drugs12, FC_DT, StochasticCut, cut, K, c, CD4, Drug1, Drug2, Drug3, Drug4, Dosing_Interval, Therapy_Type, stop_restart_DT, Aim3RoundingErrors));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_evonet_viral_dynamics_aim3", (DL_FUNC) &_evonet_viral_dynamics_aim3, 55},
    {NULL, NULL, 0}
};

RcppExport void R_init_evonet(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
