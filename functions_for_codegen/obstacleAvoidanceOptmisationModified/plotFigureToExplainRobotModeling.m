 
linkSegmentsWithJoints = createLineSegmentsWithJoints(mdhparams,robot,[0.1,0.1,0.07,0.08,0.07,0,0.08],[0.1,0.1,0.06,0.04,0.05,0,0.08],Homejointpositions);

av0 = linkSegmentsWithJoints(5).aSegmentV0;
av1 = linkSegmentsWithJoints(5).aSegmentV1;
dv0 = linkSegmentsWithJoints(5).dSegmentV0;
dv1 = linkSegmentsWithJoints(5).dSegmentV1;

linkSegment4av0 = linkSegmentsWithJoints(4).aSegmentV0;
linkSegment4av1 = linkSegmentsWithJoints(4).aSegmentV1;
linkSegment4dv0 = linkSegmentsWithJoints(4).dSegmentV0;
linkSegment4dv1 = linkSegmentsWithJoints(4).dSegmentV1;
radiusLink4 = linkSegmentsWithJoints(4).radius;
radiusJoint4 = linkSegmentsWithJoints(4).radiusJoint;

linkSegment3av0 = linkSegmentsWithJoints(3).aSegmentV0;
linkSegment3av1 = linkSegmentsWithJoints(3).aSegmentV1;
linkSegment3dv0 = linkSegmentsWithJoints(3).dSegmentV0;
linkSegment3dv1 = linkSegmentsWithJoints(3).dSegmentV1;
radiusLink3 = linkSegmentsWithJoints(3).radius;
radiusJoint3 = linkSegmentsWithJoints(3).radiusJoint;
plotCylinder(linkSegment3dv0',linkSegment3dv1',radiusLink3,'g',0.3);
hold on;
plotSphere(linkSegment3dv0,radiusJoint3,'g',0.3);
% 
% plotCylinder(linkSegment4av0',linkSegment4av1',radiusLink4,'b',0.3);
% plotSphere(linkSegment4av0',radiusJoint4,'g',0.3);



radiusLink = linkSegmentsWithJoints(5).radius;
radiusJoint = linkSegmentsWithJoints(5).radiusJoint;
frame4 = getTransform(robot,Homejointpositions,'robot_link4','base');

frame5 = getTransform(robot,Homejointpositions,'robot_link5','base');
frame3 = getTransform(robot,Homejointpositions,'robot_link3','base');
frame2 = getTransform(robot,Homejointpositions,'robot_link2','base');

hold on;
plotCylinder(av0',av1',radiusLink,'r',0.3)
%show(frankarobot,Initalconfig,'Frames','off','PreservePlot',true);
show(robot,Homejointpositions,'Frames','off','PreservePlot',true);

plotSphere(av0,radiusJoint,'r',0.3)
plotline(av0,av1,'Color','k','LineWidth',3,'LineStyle',':')


plotCylinder(dv0',dv1',radiusLink,'r',0.3);
hold on;




plotSphere(dv0,radiusJoint,'r',0.3);
plotline(dv0,dv1,'Color','k','LineWidth',3,'LineStyle',':');
plotSmallCoordinateSystem(frame4,0.08);
plotSmallCoordinateSystem(frame5,0.08);
%plotSmallCoordinateSystem(eye(4),0.1);
plotSmallCoordinateSystem(frame3,0.08);
plotSmallCoordinateSystem(frame2,0.08);

plotline(linkSegment3dv0,linkSegment3dv1,'Color','k','LineWidth',3,'LineStyle',':');

% 
xlim([-0.1, 0.7]);
  ylim([-0.2, 0.2]);
 zlim([0,0.8])
view(3)
