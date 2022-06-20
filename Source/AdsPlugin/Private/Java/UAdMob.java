package com.Plugins.AdsPlugin;

public class UAdMob {

	private InterstitialAd interstitialAd;

	public static native void OnSuccessAd(boolean IsSuccess);

	
	public void InitAds(){
		interstitialAd = new InterstitialAd(this);
		interstitialAd.setAdUnitId("ca-app-pub-3940256099942544/1033173712");
		interstitialAd.loadAd(new AdRequest.Builder().addTestDevice("D11123E2049EE9FF2D0F5B3B6D8EDEA4").build());
	}

	public void showInterstitialAd(){
		runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if (interstitialAd.isLoaded()){
					interstitialAd.show();
					OnSuccessAd(true);
				} else {
					OnSuccessAd(false);
					InitAds();
				}
			}
		});
	}
}