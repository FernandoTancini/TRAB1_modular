PFZ_tpCondRet PFZ_CriarListaPecasFinalizadas(
  PFZ_tpPecasFinalizadas *pPecasFinalizadas);
PFZ_tpCondRet PFZ_InserirPeca(PFZ_tpPecasFinalizadas pPecasFinalizadas, tppPeca pPeca);
PFZ_tpCondRet PFZ_ContarPecas(PFZ_tpPecasFinalizadas pPecasFinalizadas, PEC_CorDaPeca  CorPeca, int *pContagem);
PFZ_tpCondRet PFZ_DestruirListaPecasFinalizadas(PFZ_tpPecasFinalizadas *pPecasFinalizadas);
