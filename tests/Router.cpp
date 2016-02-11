#include "photon/Router.h"

#include <gtest/gtest.h>

class PhotonRouterTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        PhotonRouter_Init();
    }

    void TearDown() override
    {
        PhotonRouter_ClearRoutes();
        PhotonRouter_ClearGroupRoutes();
    }
private:
};

TEST_F(PhotonRouterTest, afterInit)
{
    PhotonGtRouterError rv;
    rv = PhotonRouter_GetNextHop(0, 0);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_NO_SUCH_ADDRESS, rv);
}

TEST_F(PhotonRouterTest, setRoute)
{
    PhotonGtRouterError rv;
    rv = PhotonRouter_SetRoute(2, 5);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_OK, rv);
    rv = PhotonRouter_SetRoute(11, 23);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_OK, rv);

    PhotonGtAddress value;
    rv = PhotonRouter_GetNextHop(2, &value);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_OK, rv);
    EXPECT_EQ(5, value);

    rv = PhotonRouter_GetNextHop(11, &value);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_OK, rv);
    EXPECT_EQ(23, value);

    rv = PhotonRouter_GetNextHop(145, &value);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_NO_SUCH_ADDRESS, rv);
}

TEST_F(PhotonRouterTest, delRoute)
{
    PhotonGtRouterError rv;
    rv = PhotonRouter_SetRoute(10, 26);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_OK, rv);

    rv = PhotonRouter_DelRoute(10);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_OK, rv);

    PhotonGtAddress value;
    rv = PhotonRouter_GetNextHop(10, &value);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_NO_SUCH_ADDRESS, rv);

    rv = PhotonRouter_DelRoute(10);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_NO_SUCH_ADDRESS, rv);
}

TEST_F(PhotonRouterTest, delRouteConnotRoute)
{
    PhotonGtRouterError rv;
    rv = PhotonRouter_SetRoute(101, 101);
    EXPECT_EQ(PHOTON_GT_ROUTER_ERROR_CANNOUT_ROUTE, rv);
}
