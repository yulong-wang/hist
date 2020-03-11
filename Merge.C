{
TFile f("calib.root");
TH1D *bb = (TH1D *)f.Get("h_mjpt_l200_nmjpt_l100_mjmeanSd0_BB_Nom");
TH1D *bl = (TH1D *)f.Get("h_mjpt_l200_nmjpt_l100_mjmeanSd0_BL_Nom");
TH1D *cc = (TH1D *)f.Get("h_mjpt_l200_nmjpt_l100_mjmeanSd0_CC_Nom");
TH1D *cl = (TH1D *)f.Get("h_mjpt_l200_nmjpt_l100_mjmeanSd0_CL_Nom");
TH1D *ll = (TH1D *)f.Get("h_mjpt_l200_nmjpt_l100_mjmeanSd0_LL_Nom");
TH1D *dataout = (TH1D *)f.Get("h_mjpt_l200_nmjpt_l100_mjmeanSd0_Data_Nom");
auto bbout = new TH1D("bb", "BB", 100, -40, 60);
auto blout = new TH1D("bl", "BL", 100, -40, 60);
auto ccout = new TH1D("cc", "CC", 100, -40, 60);
auto clout = new TH1D("cl", "CL", 100, -40, 60);
auto llout = new TH1D("ll", "LL", 100, -40, 60);
i = 1;
while (i < 101) {
	bbout->SetBinContent(i, bb->GetBinContent(i));
	i++;
}
i = 1;
while (i < 101) {
	blout->SetBinContent(i, bl->GetBinContent(i));
	i++;
}
i = 1;
while (i < 101) {
	ccout->SetBinContent(i, cc->GetBinContent(i));
	i++;
}
i = 1;
while (i < 101) {
	clout->SetBinContent(i, cl->GetBinContent(i));
	i++;
}
i = 1;
while (i < 101) {
	llout->SetBinContent(i, ll->GetBinContent(i));
	i++;
}
i = 1;
bbout->SetFillColor(kAzure);
blout->SetFillColor(kAzure-4);
ccout->SetFillColor(kGreen+3);
clout->SetFillColor(kGreen-9);
llout->SetFillColor(kOrange-2);
auto legend = new TLegend(0.75, 0.65, 0.9, 0.9);
legend->SetHeader("", "C");
legend->AddEntry(bbout, "BB", "f");
legend->AddEntry(blout, "BL", "f");
legend->AddEntry(ccout, "CC", "f");
legend->AddEntry(clout, "CL", "f");
legend->AddEntry(llout, "LL", "f");
legend->AddEntry(dataout, "Data", "lep");
THStack* out = new THStack("out", ";muon-jet mean s_d0;Events");
out->Add(bbout);
out->Add(blout);
out->Add(ccout);
out->Add(clout);
out->Add(llout);
out->Add(dataout);
auto canv = new TCanvas("canv", "canv", 600, 500);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
canv->cd(1); out->Draw(); T.DrawTextNDC(.5, .95, "mjpt < 200, nmjpt < 100, muon-jet mean s_d0");
legend->Draw();
}